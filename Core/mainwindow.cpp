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
}

MainWindow::~MainWindow()
{
    delete ui;
}

