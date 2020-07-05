#include "vtkscenewidget.h"

#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkAxesActor.h>
#include <vtkCaptionActor2D.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>

vtkSmartPointer<vtkAxesActor> VTKSceneWidget::createAxesActor(const float &length)
{
    vtkSmartPointer<vtkAxesActor> axesActor = vtkSmartPointer<vtkAxesActor>::New();
    axesActor->SetTotalLength(length, length, length);
    axesActor->SetConeRadius(0.1);
    axesActor->SetAxisLabels(0);
    axesActor->GetXAxisCaptionActor2D()->GetTextActor()->SetTextScaleMode(vtkTextActor::TEXT_SCALE_MODE_NONE);
    axesActor->GetXAxisCaptionActor2D()->GetTextActor()->GetTextProperty()->SetFontSize(12);
    axesActor->GetYAxisCaptionActor2D()->GetTextActor()->SetTextScaleMode(vtkTextActor::TEXT_SCALE_MODE_NONE);
    axesActor->GetYAxisCaptionActor2D()->GetTextActor()->GetTextProperty()->SetFontSize(12);
    axesActor->GetZAxisCaptionActor2D()->GetTextActor()->SetTextScaleMode(vtkTextActor::TEXT_SCALE_MODE_NONE);
    axesActor->GetZAxisCaptionActor2D()->GetTextActor()->GetTextProperty()->SetFontSize(12);
    return axesActor;
}

VTKSceneWidget::VTKSceneWidget(QWidget *parent)
    : QVTKOpenGLNativeWidget(parent)
{
    m_renderer = vtkSmartPointer<vtkRenderer>::New();
    this->renderWindow()->AddRenderer(m_renderer);
}

void VTKSceneWidget::prepare()
{
    m_renderer->SetBackground(0.35, 0.45, 0.55);
    m_renderer->SetGradientBackground(true);
    m_renderer->SetBackground2(0.7, 0.75, 0.8);

    m_axesActor = createAxesActor(100.0);
    m_renderer->AddActor(m_axesActor);
}
