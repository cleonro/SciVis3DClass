#include "odestate.h"

#include <QDebug>

ODEState::ODEState(QObject *parent)
    : StageState(parent)
{
    this->setActivateStageActionTitle("ODE - Ordinary Differential Equations");
}

void ODEState::init()
{
    qDebug() << "ODEstate initialized.";
}

void ODEState::clear()
{
    qDebug() << "ODEState cleared.";
}
