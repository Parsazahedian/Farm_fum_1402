#include "mainwindow.h"
#include <QApplication>

MainWindow* mainWindowPtr = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    mainWindowPtr = &w;
    w.show();
    return a.exec();
}
