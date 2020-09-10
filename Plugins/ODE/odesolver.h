#ifndef ODESOLVER_H
#define ODESOLVER_H

#include <QObject>

#include <functional>

class ODESolver : public QObject
{
    Q_OBJECT

public:

    enum class State
    {
        IDLE,
        SOLVING_STARTED,
        SOLVING_FINISHED
    };

    using ODESystemFunction = std::function<int(double t, const double y[], double f[], void *params)>;
    using ODESystemJacobian = std::function<int(double t, const double y[], double *dfdy, double dfdt[], void *params)>;

    typedef int ODESystemFunction_C(double t, const double y[], double f[], void *params);
    typedef int ODESystemJacobian_C(double t, const double y[], double *dfdy, double dfdt[], void *params);

public:
    explicit ODESolver(QObject *parent = nullptr);

    State state();

    void solve(int order, ODESystemFunction_C function, ODESystemJacobian_C jacobian, double params[], double y[], int size, double t0, double t1);

signals:
    void started(int dimension);
    void stepValue(double value);
    void stepFunctionValue(int index, double value);
    void finished();

private:
    State m_state;

};

#endif // ODESOLVER_H
