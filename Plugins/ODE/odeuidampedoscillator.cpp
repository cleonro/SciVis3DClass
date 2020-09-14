#include "odeuidampedoscillator.h"
#include "ui_odeuidampedoscillator.h"
#include "odeexamples.h"
#include "odecontroller.h"

ODEUiDampedOscillator::ODEUiDampedOscillator(QWidget *parent)
    : ODEInterface(parent)
    , ui(new Ui::ODEUiDampedOscillator)
    , m_controller(nullptr)
{
    ui->setupUi(this);

    m_parameters[0] = ui->r->value();
    m_parameters[1] = ui->w->value();

    m_state[0] = ui->position->value();
    m_state[1] = ui->speed->value();
}

ODEUiDampedOscillator::~ODEUiDampedOscillator()
{
    delete ui;
}

int ODEUiDampedOscillator::order()
{
    return 2;
}

ODESolver::ODESystemFunction_C & ODEUiDampedOscillator::systemFunction()
{
    return ODEExamples::dampedOscillatorFunction;
    //return ODEExamples::realPendulumFunction;
}

ODESolver::ODESystemJacobian_C & ODEUiDampedOscillator::systemJacobian()
{
    return ODEExamples::dampedOscillatorJacobian;
    //return ODEExamples::realPendulumJacobian;
}

double * ODEUiDampedOscillator::parameters()
{
    m_parameters[0] = ui->r->value();
    m_parameters[1] = ui->w->value();
    return m_parameters;
}

double * ODEUiDampedOscillator::stateVector()
{
    m_state[0] = ui->position->value();
    m_state[1] = ui->speed->value();
    return m_state;
}

int ODEUiDampedOscillator::solutionSize()
{
    return 1000;
}

double ODEUiDampedOscillator::timeStart()
{
    return 0;
}

double ODEUiDampedOscillator::timeStop()
{
    return ui->time->value();
}

void ODEUiDampedOscillator::setController(ODEController *controller)
{
    m_controller = controller;
}

void ODEUiDampedOscillator::on_compute_clicked()
{
    m_controller->startComputing(this);
}

void ODEUiDampedOscillator::on_clear_clicked()
{
    m_controller->clearGraph();
}
