#ifndef ODEUIDAMPEDOSCILLATOR_H
#define ODEUIDAMPEDOSCILLATOR_H

#include "odeinterface.h"

namespace Ui {
class ODEUiDampedOscillator;
}

class ODEUiDampedOscillator : public ODEInterface
{
    Q_OBJECT

public:
    explicit ODEUiDampedOscillator(QWidget *parent = nullptr);
    ~ODEUiDampedOscillator();

    int order() override;
    ODESolver::ODESystemFunction_C & systemFunction() override;
    ODESolver::ODESystemJacobian_C & systemJacobian() override;
    double * parameters() override;
    double * stateVector() override;
    int solutionSize() override;
    double timeStart() override;
    double timeStop() override;
    void setController(ODEController *controller) override;

private slots:
    void on_compute_clicked();

    void on_clear_clicked();

private:
    Ui::ODEUiDampedOscillator *ui;

    double m_parameters[2];
    double m_state[2];

    ODEController *m_controller;
};

#endif // ODEUIDAMPEDOSCILLATOR_H
