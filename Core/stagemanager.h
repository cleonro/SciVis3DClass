#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

#include "CoreDefines.h"
#include "mainwindow.h"
#include "stagestate.h"

#include <QObject>

#define STAGEMNGR StageManager::instance()

class QAction;

class Core_EXPORT StageManager : public QObject
{
    Q_OBJECT
public:
    static StageManager & instance();

    MainWindow * mainWindow();
    void setMainWindow(MainWindow *mainWindow);

    void setStageState(StageState *stageStage);

    void loadPlugins();

signals:

private slots:
    void onEmptyStageAction(bool toggled);

private:
    explicit StageManager(QObject *parent = nullptr);

private:
    MainWindow *m_mainWindow;
    StageState *m_stageState;
    QAction *m_emptyStageAction;
};

#endif // STAGEMANAGER_H
