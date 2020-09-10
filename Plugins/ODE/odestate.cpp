#include "odestate.h"
#include "stagemanager.h"
#include "odecontroller.h"
#include "odeuidampedoscillator.h"

#include <QDockWidget>
#include <QMenu>
#include <QDebug>

ODEState::ODEState(QObject *parent)
    : StageState(parent)
{
    this->setActivateStageActionTitle("ODE - Ordinary Differential Equations");
    m_controller = new ODEController(this);

    MainWindow *mainWindow = STAGEMNGR.mainWindow();
    m_odeInterface = new ODEUiDampedOscillator(mainWindow);
    m_odeInterface->setController(m_controller);

    QDockWidget *docWidget = new QDockWidget(mainWindow);
    docWidget->setWindowTitle(tr("ODE - Damped Oscillator"));
    docWidget->setWidget(m_odeInterface);
    QAction *docAction = docWidget->toggleViewAction();
    mainWindow->addDockWidget(Qt::LeftDockWidgetArea, docWidget);
    mainWindow->menu(MainWindow::MenuType::View)->addAction(docAction);
    docWidget->hide();
}

void ODEState::init()
{
    qDebug() << "ODEstate initialized.";
    m_controller->init();
}

void ODEState::clear()
{
    qDebug() << "ODEState cleared.";
    m_controller->clear();
}
