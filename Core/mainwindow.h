#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CoreDefines.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class VTKSceneWidget;

class Core_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void prepareScene();

private:
    Ui::MainWindow *ui;
    VTKSceneWidget *m_scene;
};
#endif // MAINWINDOW_H
