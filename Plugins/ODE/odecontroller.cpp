#include "odecontroller.h"
#include "stagemanager.h"
#include "vtkscenewidget.h"

#include <vtkRenderer.h>
#include <vtkContextScene.h>
#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkFloatArray.h>
#include <vtkPlot.h>
#include <vtkContextActor.h>
#include <vtkRenderWindow.h>

#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingContextOpenGL2);

#include <QDebug>

ODEController::ODEController(QObject *parent) : QObject(parent)
{
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

void ODEController::createVTKObjects()
{
    m_chart = vtkSmartPointer<vtkChartXY>::New();
    m_actor = vtkSmartPointer<vtkContextActor>::New();
    m_actor->GetScene()->AddItem(m_chart);

    createSinCosGraph();
}

void ODEController::createSinCosGraph()
{
    // Create a table with some points in it
    vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();

    vtkSmartPointer<vtkFloatArray> arrX = vtkSmartPointer<vtkFloatArray>::New();
    arrX->SetName("X Axis");
    table->AddColumn(arrX);

    vtkSmartPointer<vtkFloatArray> arrC = vtkSmartPointer<vtkFloatArray>::New();
    arrC->SetName("Cosine");
    table->AddColumn(arrC);

    vtkSmartPointer<vtkFloatArray> arrS = vtkSmartPointer<vtkFloatArray>::New();
    arrS->SetName("Sine");
    table->AddColumn(arrS);

    // Fill in the table with some example values
    int numPoints = 69;
    float inc = 7.5 / (numPoints - 1);
    table->SetNumberOfRows(numPoints);
    for (int i = 0; i < numPoints; ++i)
    {
        table->SetValue(i, 0, i * inc);
        table->SetValue(i, 1, cos(i * inc));
        table->SetValue(i, 2, sin(i * inc));
    }

    vtkPlot *line = m_chart->AddPlot(vtkChart::LINE);
    line->SetInputData(table, 0, 1);
    line->SetColor(0, 255, 0, 255);
    line->SetWidth(1.0);

    line = m_chart->AddPlot(vtkChart::LINE);
    line->SetInputData(table, 0, 2);
    line->SetColor(255, 0, 0, 255);
    line->SetWidth(5.0);
}
