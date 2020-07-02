#include "stagemanager.h"

#include <QPluginLoader>
#include <QDir>
#include <QApplication>
#include <QDebug>

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

void StageManager::setStageState(StageState *stageStage)
{
    if(m_stageState != nullptr)
    {
        m_stageState->clear();
    }
    m_stageState = stageStage;
    if(m_stageState != nullptr)
    {
        m_stageState->init();
    }
}

void StageManager::loadPlugins()
{
    QDir pluginsDir = QDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    const auto entryList = pluginsDir.entryList(QStringList() << "*SciVis3DClassPlugin.*", QDir::Files);
    for (const QString &fileName : entryList)
    {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin)
        {
            StageState *state = qobject_cast<StageState*>(plugin);
            if(state != nullptr)
            {
                qDebug() << "Found a stage state!";
            }
        }

    }
}
