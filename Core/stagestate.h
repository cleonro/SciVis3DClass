#ifndef STAGESTATE_H
#define STAGESTATE_H

#include <QObject>

class QAction;

class StageState : public QObject
{
    Q_OBJECT
public:
    explicit StageState(QObject *parent = nullptr);
    virtual ~StageState();

    StageState(StageState &) = delete;
    StageState(StageState &&) = delete;
    StageState & operator=(const StageState &) = delete;
    StageState & operator=(const StageState &&) = delete;

    virtual void linkToApp();
    virtual void init() = 0;
    virtual void clear() = 0;

signals:

protected:
    void setActivateStageActionTitle(const QString &title);

private slots:
    void onActivateStageAction(bool toggled);

private:
    QAction *m_activateStage;
};

#define StageState_iid "org.SciVis3DClass.StageStage"
Q_DECLARE_INTERFACE(StageState, StageState_iid)

#endif // STAGESTATE_H
