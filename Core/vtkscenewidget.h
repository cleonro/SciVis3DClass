#ifndef VTKSCENEWIDGET_H
#define VTKSCENEWIDGET_H

#include <QVTKOpenGLNativeWidget.h>
#include <vtkSmartPointer.h>

class vktRenderer;
class vtkAxesActor;

class VTKSceneWidget : public QVTKOpenGLNativeWidget
{
    Q_OBJECT
public:
    static vtkSmartPointer<vtkAxesActor> createAxesActor(const float &length);

public:
    VTKSceneWidget(QWidget *parent = nullptr);

    void prepare();

    vtkRenderer * renderer();

private:
    vtkSmartPointer<vtkRenderer> m_renderer;
    vtkSmartPointer<vtkAxesActor> m_axesActor;
};

#endif // VTKSCENEWIDGET_H
