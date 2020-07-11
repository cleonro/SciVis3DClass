#include "odestate.h"
#include "odecontroller.h"

#include <QDebug>

ODEState::ODEState(QObject *parent)
    : StageState(parent)
{
    this->setActivateStageActionTitle("ODE - Ordinary Differential Equations");
    m_controller = new ODEController(this);
}

void ODEState::init()
{
    qDebug() << "ODEstate initialized.";
    m_controller->init();
}

void ODEState::clear()
{
    qDebug() << "ODEState cleared.";
    m_controller->clear();
}
