#include "odecontroller.h"
#include "stagemanager.h"
#include "vtkscenewidget.h"
#include "odesolver.h"
#include "odeinterface.h"

#include <vtkRenderer.h>
#include <vtkContextScene.h>
#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkDoubleArray.h>
#include <vtkPlot.h>
#include <vtkContextActor.h>
#include <vtkRenderWindow.h>
#include <vtkTextProperty.h>
#include <vtkAxis.h>

#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingContextOpenGL2);

#include <QDebug>

#include <sstream>

ODEController::ODEController(QObject *parent)
    : QObject(parent)
{
    m_solver = new ODESolver(this);

    connect(m_solver, &ODESolver::started, this, &ODEController::onStarted);
    connect(m_solver, &ODESolver::stepValue, this, &ODEController::onStepValue);
    connect(m_solver, &ODESolver::stepFunctionValue, this, &ODEController::onStepFunctionValue);
    connect(m_solver, &ODESolver::finished, this, &ODEController::onFinished);

    createVTKObjects();
}

void ODEController::init()
{
    VTKSceneWidget * scene = STAGEMNGR.mainWindow()->sceneWidget();
    vtkRenderer *renderer = scene->renderer();
    renderer->AddActor(m_actor);
    scene->setAxesVisible(false);
    renderer->GetRenderWindow()->Render();
}

void ODEController::clear()
{
    VTKSceneWidget * scene = STAGEMNGR.mainWindow()->sceneWidget();
    vtkRenderer *renderer = scene->renderer();
    renderer->RemoveActor(m_actor);
    scene->setAxesVisible(true);
    renderer->GetRenderWindow()->Render();
}

void ODEController::clearGraph()
{
    int tableColumns = m_table->GetNumberOfColumns();
    while(tableColumns > 0)
    {
        m_table->RemoveColumn(0);
        tableColumns = m_table->GetNumberOfColumns();
    }

    int numberOfPlots = m_chart->GetNumberOfPlots();
    while(numberOfPlots > 0)
    {
        m_chart->RemovePlot(0);
        numberOfPlots = m_chart->GetNumberOfPlots();
    }

    m_solutionColumns.clear();

    VTKSceneWidget * scene = STAGEMNGR.mainWindow()->sceneWidget();
    vtkRenderer *renderer = scene->renderer();
    renderer->GetRenderWindow()->Render();
}

void ODEController::startComputing(ODEInterface *ode)
{
    m_solver->solve(
                ode->order(),
                ode->systemFunction(),
                ode->systemJacobian(),
                ode->parameters(),
                ode->stateVector(),
                ode->solutionSize(),
                0.0,
                ode->timeStop()
                );
}

void ODEController::onStarted(int dimension)
{
    // clear existing information
    clearGraph();

    // create data table
    m_solutionColumns.resize(dimension + 1);
    for(int i = 0; i <= dimension; ++i)
    {
        m_solutionColumns[i] = vtkSmartPointerDoubleArray::New();
        m_table->AddColumn(m_solutionColumns[i]);
    }

    m_solutionColumns[0]->SetName("Time");
    m_solutionColumns[1]->SetName("Solution");
    for(int i = 2; i <= dimension; ++i)
    {
        std::ostringstream os;
        os << "Derivative - order " <<  i - 1;
        m_solutionColumns[i]->SetName(os.str().c_str());
    }
}

void ODEController::onStepValue(double value)
{
    m_table->InsertNextBlankRow();
    int row = m_table->GetNumberOfRows() - 1;
    m_table->SetValue(row, 0, value);
}

void ODEController::onStepFunctionValue(int index, double value)
{
    int row = m_table->GetNumberOfRows() - 1;
    m_table->SetValue(row, index + 1, value);
}

void ODEController::onFinished()
{
    // create graphs
    int columns = m_table->GetNumberOfColumns();
    int maxColor = columns - 1;
    for(int i = 1; i < columns; ++i)
    {
        vtkPlot *line = m_chart->AddPlot(vtkChart::LINE);
        line->SetInputData(m_table, 0, i);
        double b = 0.7 * (i - 1) / (maxColor - 1);
        double g = 0.1;
        double r = 0.7 - 0.7 * (i - 1) / (maxColor - 1);
        line->SetColor(r, g, b);
    }

    m_chart->Update();
    VTKSceneWidget * scene = STAGEMNGR.mainWindow()->sceneWidget();
    vtkRenderer *renderer = scene->renderer();
    renderer->GetRenderWindow()->Render();
}

void ODEController::createVTKObjects()
{
    m_table = vtkSmartPointer<vtkTable>::New();

    m_chart = vtkSmartPointer<vtkChartXY>::New();
    m_actor = vtkSmartPointer<vtkContextActor>::New();
    m_actor->GetScene()->AddItem(m_chart);

    m_chart->SetTitle("ODE Numerical Solution");
    m_chart->GetTitleProperties()->SetBold(true);
    m_chart->GetTitleProperties()->SetFontSize(18);

    m_chart->GetAxis(vtkAxis::BOTTOM)->SetTitle("Time");
    m_chart->GetAxis(vtkAxis::BOTTOM)->GetTitleProperties()->SetFontSize(16);

    m_chart->GetAxis(vtkAxis::LEFT)->SetTitle("Solution");
    m_chart->GetAxis(vtkAxis::LEFT)->GetTitleProperties()->SetFontSize(16);
}
