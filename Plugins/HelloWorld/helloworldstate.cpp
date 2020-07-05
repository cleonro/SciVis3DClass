#include "helloworldstate.h"
#include "helloworldcontroller.h"

#include <QDebug>

HelloWorldState::HelloWorldState(QObject *parent)
    : StageState(parent)
{
    this->setActivateStageActionTitle("Hello, World!");
    m_controller = new HelloWorldController(this);
}

void HelloWorldState::init()
{
    qDebug() << "HelloWorld initialized";
    m_controller->init();
}

void HelloWorldState::clear()
{
    qDebug() << "HelloWorld cleared";
    m_controller->clear();
}




