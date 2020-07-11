#include "stagemanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    STAGEMNGR.setMainWindow(&w);
    STAGEMNGR.loadPlugins();
    return a.exec();
}
