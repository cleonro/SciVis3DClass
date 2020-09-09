#include "odesolver.h"

#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

#include <cmath>
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
/// \brief Just an example

static int function(double t, const double y[], double f[], void *params)
{
    (void)(t);
    const double r = ((double*)params)[0];
    const double w = ((double*)params)[1];
    const double w2 = w * w;

    f[0] = y[1];
    f[1] = -r * y[1] - w2 * y[0];

    return GSL_SUCCESS;
}

static int jacobian(double t, const double y[], double *dfdy, double dfdt[], void *params)
{
    (void)(t);
    const double r = ((double*)params)[0];
    const double w = ((double*)params)[1];
    const double w2 = w * w;

    gsl_matrix_view dfdy_mat = gsl_matrix_view_array(dfdy, 2, 2);
    gsl_matrix *m = &dfdy_mat.matrix;
    gsl_matrix_set(m, 0, 0, 0.0);
    gsl_matrix_set(m, 0, 1, 1.0);
    gsl_matrix_set(m, 1, 0, -w2);
    gsl_matrix_set(m, 1, 1, -r);
    dfdt[0] = 0.0;
    dfdt[1] = 0.0;

    return GSL_SUCCESS;
}

static double params[]{M_PI / 2, 2.0 * M_PI};

///////////////////////////////////////////////////////////////////////////////

ODESolver::ODESolver(QObject *parent)
    : QObject(parent)
    , m_state(State::IDLE)
{

}

ODESolver::State ODESolver::state()
{
    return m_state;
}

void ODESolver::solve()
{
    double y[2] = { 5.0, 0.0 };
    solve(2, function, jacobian, params, y, 1000, 0.0, 10.0);
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

