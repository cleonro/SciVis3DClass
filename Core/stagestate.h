#ifndef STAGESTATE_H
#define STAGESTATE_H

#include <QObject>

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

    virtual void init() = 0;
    virtual void clear() = 0;

signals:

};

#endif // STAGESTATE_H
