#ifndef ODECONTROLLER_H
#define ODECONTROLLER_H

#include <vtkSmartPointer.h>

#include <QObject>

class vtkContextActor;
class vtkChartXY;

class ODEController : public QObject
{
    Q_OBJECT
public:
    explicit ODEController(QObject *parent = nullptr);

    void init();
    void clear();

signals:

private:
    void createVTKObjects();

private:
    void createSinCosGraph();

private:
    vtkSmartPointer<vtkContextActor> m_actor;
    vtkSmartPointer<vtkChartXY> m_chart;
};

#endif // ODECONTROLLER_H
