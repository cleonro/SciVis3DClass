#ifndef HELLOWORLDSTATE_H
#define HELLOWORLDSTATE_H

#include "stagemanager.h"

#include <QObject>

class HelloWorldState : public StageState
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.SciVis3D.HelloWorld.HelloWorldState")
    Q_INTERFACES(StageState)

public:
    explicit HelloWorldState(QObject *parent = nullptr);

    void init() override;
    void clear() override;

signals:

};

#endif // HELLOWORLDSTATE_H
