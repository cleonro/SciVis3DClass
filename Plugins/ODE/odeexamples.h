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

};

#endif // ODEEXAMPLES_H
