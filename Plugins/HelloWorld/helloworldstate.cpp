#include "helloworldstate.h"

#include <QDebug>

HelloWorldState::HelloWorldState(QObject *parent)
    : StageState(parent)
{
    this->setActivateStageActionTitle("Hello, World!");
}

void HelloWorldState::init()
{
    qDebug() << "HelloWorld initialized";
}

void HelloWorldState::clear()
{
    qDebug() << "HelloWorld cleared";
}

