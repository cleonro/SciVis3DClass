#include "stagemanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    STAGEMNGR.setMainWindow(&w);
    w.show();
    return a.exec();
}
