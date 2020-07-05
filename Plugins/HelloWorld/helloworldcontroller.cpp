#include "helloworldcontroller.h"
#include "stagemanager.h"
#include "vtkscenewidget.h"

#include <vtkRenderer.h>
#include <vtkVectorText.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>

HelloWorldController::HelloWorldController(QObject *parent) : QObject(parent)
{
    this->createTextActor();
}

void HelloWorldController::init()
{
    VTKSceneWidget *scene = STAGEMNGR.mainWindow()->sceneWidget();
    vtkRenderer *renderer = scene->renderer();
    renderer->AddActor(m_textActor);
    scene->renderWindow()->Render();
}

void HelloWorldController::clear()
{
    VTKSceneWidget *scene = STAGEMNGR.mainWindow()->sceneWidget();
    vtkRenderer *renderer = scene->renderer();
    renderer->RemoveActor(m_textActor);
    scene->renderWindow()->Render();
}

void HelloWorldController::createTextActor()
{
    vtkSmartPointer<vtkVectorText> textSource = vtkSmartPointer<vtkVectorText>::New();
    textSource->SetText("Hello, SciVis3DClass!");
    textSource->Update();

    // Create a mapper and actor
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(textSource->GetOutput());

    m_textActor = vtkSmartPointer<vtkActor>::New();
    m_textActor->SetMapper(mapper);
    m_textActor->GetProperty()->SetColor(0.1, 0.2, 0.7);
    m_textActor->SetScale(10.0, 10.0, 10.0);

    double *bounds = m_textActor->GetBounds();
    double xmin = bounds[0];
    double xmax = bounds[1];
    double ymin = bounds[2];
    double ymax = bounds[3];
    double zmin = bounds[4];
    double zmax = bounds[5];

    double xcenter = 0.5 * (xmax + xmin);
    double ycenter = 0.5 * (ymax + ymin);
    double zcenter = 0.5 * (zmax + zmin);

    m_textActor->SetPosition(-xcenter, -ycenter, -zcenter);
}
