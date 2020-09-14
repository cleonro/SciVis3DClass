#ifndef ODEEXAMPLES_H
#define ODEEXAMPLES_H

class ODEExamples
{
public:
    ODEExamples() = default;

    ///
    /// \brief Damped Oscillator differential equations system
    ///
    static int dampedOscillatorFunction(double t, const double y[], double f[], void *params);
    static int dampedOscillatorJacobian(double t, const double y[], double *dfdy, double dfdt[], void *params);

    ///
    /// \brief Real Pendulum (large amplitude) differential equations system
    ///
    static int realPendulumFunction(double t, const double y[], double f[], void *params);
    static int realPendulumJacobian(double t, const double y[], double *dfdy, double dfdt[], void *params);

};

#endif // ODEEXAMPLES_H
