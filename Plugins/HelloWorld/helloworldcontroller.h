#ifndef HELLOWORLDCONTROLLER_H
#define HELLOWORLDCONTROLLER_H

#include <vtkSmartPointer.h>

#include <QObject>

class vtkActor;

class HelloWorldController : public QObject
{
    Q_OBJECT
public:
    explicit HelloWorldController(QObject *parent = nullptr);

    void init();
    void clear();

signals:

private:
    void createTextActor();

private:
    vtkSmartPointer<vtkActor> m_textActor;

};

#endif // HELLOWORLDCONTROLLER_H
