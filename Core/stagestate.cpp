#include "stagestate.h"
#include "stagemanager.h"

#include <QAction>

StageState::StageState(QObject *parent)
    : QObject(parent)
{
    m_activateStage = new QAction("Stage", this);
    connect(m_activateStage, &QAction::toggled, this, &StageState::onActivateStageAction);
}

StageState::~StageState()
{

}

void StageState::linkToApp()
{
    STAGEMNGR.mainWindow()->addStageAction(m_activateStage);
}

void StageState::onActivateStageAction(bool toggled)
{
    if(toggled)
    {
        this->init();
    }
    else
    {
        this->clear();
    }
}

void StageState::setActivateStageActionTitle(const QString &title)
{
    m_activateStage->setText(title);
}
