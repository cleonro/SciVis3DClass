#ifndef PDE1STATE_H
#define PDE1STATE_H

#include "stagemanager.h"

class PDE1State : public StageState
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.SciVis3D.PDE1.PDE1State")
    Q_INTERFACES(StageState)

public:
    PDE1State(QObject *parent = nullptr);

    void init() override;
    void clear() override;

private:

};

#endif // PDE1STATE_H
