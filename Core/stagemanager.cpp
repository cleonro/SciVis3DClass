#include "stagemanager.h"

StageManager::StageManager(QObject *parent)
    : QObject(parent)
    , m_mainWindow(nullptr)
    , m_stageState(nullptr)
{

}

StageManager & StageManager::instance()
{
    static StageManager st;
    return st;
}

MainWindow * StageManager::mainWindow()
{
    return m_mainWindow;
}

void StageManager::setMainWindow(MainWindow *mainWindow)
{
    m_mainWindow = mainWindow;
}

void StageManager::clearStage()
{
    if(m_stageState != nullptr)
    {
        m_stageState->clear();
        m_stageState->deleteLater();
        m_stageState = nullptr;
    }
}

void StageManager::setStageState(StageState *stageStage)
{
    if(m_stageState != nullptr)
    {
        m_stageState->clear();
        m_stageState->deleteLater();
    }
    m_stageState = stageStage;
    if(m_stageState != nullptr)
    {
        m_stageState->init();
    }
}
