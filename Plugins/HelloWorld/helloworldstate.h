#ifndef HELLOWORLDSTATE_H
#define HELLOWORLDSTATE_H

#include "stagemanager.h"

#include <QObject>

class HelloWorldController;

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

private:
    HelloWorldController *m_controller;

};

#endif // HELLOWORLDSTATE_H
