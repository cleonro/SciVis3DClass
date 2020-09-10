#ifndef ODESTATE_H
#define ODESTATE_H

#include "stagemanager.h"

#include <QObject>

class ODEController;
class ODEInterface;

class ODEState : public StageState
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.SciVis3D.ODE.ODEState")
    Q_INTERFACES(StageState)

public:
    ODEState(QObject *parent = nullptr);

    void init() override;
    void clear() override;

private:
    ODEController *m_controller;
    ODEInterface *m_odeInterface;
};

#endif // ODESTATE_H
