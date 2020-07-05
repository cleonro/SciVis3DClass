#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "vtkscenewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_Quit, &QAction::triggered, qApp, &QApplication::quit);

    m_scene = new VTKSceneWidget(this);
    setCentralWidget(m_scene);
    m_scene->prepare();

    m_stageActionGroup = new QActionGroup(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

VTKSceneWidget * MainWindow::sceneWidget()
{
    return m_scene;
}

QMenu * MainWindow::menu(MenuType menuType)
{
    QMenu *result = nullptr;

    QString menuName;
    switch (menuType)
    {
    case MenuType::Stage:
        menuName = "&Stage";
        break;
    case MenuType::View:
        menuName = "&View";
        break;
    case MenuType::Dialogs:
        menuName = "&Dialogs";
        break;
    }

    QList<QMenu*> menuList = ui->menubar->findChildren<QMenu*>();
    for(auto menu : menuList)
    {
        if(menu->title() == menuName)
        {
            result = menu;
            break;
        }
    }

    return result;
}

QStatusBar * MainWindow::statusBar()
{
    return ui->statusbar;
}

void MainWindow::addStageAction(QAction *action)
{
    action->setCheckable(true);
    m_stageActionGroup->addAction(action);
    QMenu *menu = this->menu(MenuType::Stage);
    menu->addAction(action);
}
