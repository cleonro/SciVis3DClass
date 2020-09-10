#include "odesolver.h"

#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

#include <cmath>
#include <iostream>

ODESolver::ODESolver(QObject *parent)
    : QObject(parent)
    , m_state(State::IDLE)
{

}

ODESolver::State ODESolver::state()
{
    return m_state;
}

void ODESolver::solve(int order, ODESystemFunction_C function, ODESystemJacobian_C jacobian, double params[], double y[], int size, double t0, double t1)
{
    m_state = State::SOLVING_STARTED;
    emit started(order);

    //gsl_odeiv2_system system = {function.target<ODESystemFunction_C>(), jacobian.target<ODESystemJacobian_C>(), 2, params};
    gsl_odeiv2_system system = {function, jacobian, 2, params};
    gsl_odeiv2_driver *driver = gsl_odeiv2_driver_alloc_y_new (&system, gsl_odeiv2_step_rk8pd, 1e-6, 1e-6, 0.0);

    double t = t0;
    double step = (t1 - t0) / (size - 1);

    std::cout << std::endl;
    bool success = true;
    for(int i = 0; i < size; ++i)
    {
        double ti = t0 + step * i;
        int status = gsl_odeiv2_driver_apply(driver, &t, ti, y);

        if (status != GSL_SUCCESS)
        {
            success = false;
            break;
        }

        emit stepValue(t);
        for(int j = 0; j < order; ++j)
        {
            emit stepFunctionValue(j, y[j]);
        }
    }

    gsl_odeiv2_driver_free(driver);
    m_state = success ? State::SOLVING_FINISHED : State::IDLE;
    emit finished();
}

