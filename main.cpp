#include "mainwindow.h"
#include <QApplication>

MainWindow* mainWindowPtr = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Farm Managment");
    w.setWindowIcon(QIcon("C:/Users/i/Downloads/businessman_3331911.png"));
    mainWindowPtr = &w;
    w.show();
    return a.exec();
}
