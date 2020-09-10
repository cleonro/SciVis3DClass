#ifndef ODEINTERFACE_H
#define ODEINTERFACE_H

#include "odesolver.h"

#include <QWidget>

class ODEController;

class ODEInterface : public QWidget
{
public:
    ODEInterface(QWidget *parent = nullptr) : QWidget(parent){};
    virtual ~ODEInterface() = default;

    virtual int order() = 0;
    virtual ODESolver::ODESystemFunction_C & systemFunction() = 0;
    virtual ODESolver::ODESystemJacobian_C & systemJacobian() = 0;
    virtual double * parameters() = 0;
    virtual double * stateVector() = 0;
    virtual int solutionSize() = 0;
    virtual double timeStart() = 0;
    virtual double timeStop() = 0;
    virtual void setController(ODEController *controller) = 0;

};

#endif // ODEINTERFACE_H
