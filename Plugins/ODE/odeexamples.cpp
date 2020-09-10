#include "odeexamples.h"

#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>

int ODEExamples::dampedOscillatorFunction(double t, const double y[], double f[], void *params)
{
    (void)(t);
    const double r = ((double*)params)[0];
    const double w = ((double*)params)[1];
    const double w2 = w * w;

    f[0] = y[1];
    f[1] = -r * y[1] - w2 * y[0];

    return GSL_SUCCESS;
}

int ODEExamples::dampedOscillatorJacobian(double t, const double y[], double *dfdy, double dfdt[], void *params)
{
    (void)(t);
    (void)(y);
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
