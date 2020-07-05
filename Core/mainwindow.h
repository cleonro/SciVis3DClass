#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CoreDefines.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class VTKSceneWidget;
class QActionGroup;

class Core_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum class Core_EXPORT MenuType
    {
        Stage,
        View,
        Dialogs
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    VTKSceneWidget * sceneWidget();
    QMenu * menu(MenuType menuType);
    QStatusBar * statusBar();

    void addStageAction(QAction *action);

private:
    void prepareScene();

private:
    Ui::MainWindow *ui;
    VTKSceneWidget *m_scene;
    QActionGroup *m_stageActionGroup;
};
#endif // MAINWINDOW_H
