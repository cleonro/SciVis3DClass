#include "pde1state.h"

#include <QDebug>

PDE1State::PDE1State(QObject *parent)
    : StageState(parent)
{
    this->setActivateStageActionTitle("PDE 1 - Partially Differential Equations");
}

void PDE1State::init()
{
    qDebug() << "PDE1State initialized.";
}

void PDE1State::clear()
{
    qDebug() << "PDE1State cleared.";
}
