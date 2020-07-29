#ifndef ODESOLVER_H
#define ODESOLVER_H

#include <QObject>

class ODESolver : public QObject
{
    Q_OBJECT
public:
    explicit ODESolver(QObject *parent = nullptr);

signals:

};

#endif // ODESOLVER_H
