#ifndef ODECONTROLLER_H
#define ODECONTROLLER_H

#include <vtkSmartPointer.h>

#include <QObject>

class vtkContextActor;
class vtkChartXY;
class vtkDoubleArray;
class vtkTable;
class ODESolver;
class ODEInterface;

class ODEController : public QObject
{
    Q_OBJECT

using vtkSmartPointerDoubleArray = vtkSmartPointer<vtkDoubleArray>;

public:
    explicit ODEController(QObject *parent = nullptr);

    void init();
    void clear();

    void clearGraph();
    void startComputing(ODEInterface *ode);

signals:

private slots:
    void onStarted(int dimension);
    void onStepValue(double value);
    void onStepFunctionValue(int index, double value);
    void onFinished();

private:
    void createVTKObjects();

private:
    vtkSmartPointer<vtkContextActor> m_actor;
    vtkSmartPointer<vtkChartXY> m_chart;
    std::vector<vtkSmartPointerDoubleArray> m_solutionColumns;
    vtkSmartPointer<vtkTable> m_table;

    ODESolver *m_solver;
};

#endif // ODECONTROLLER_H
