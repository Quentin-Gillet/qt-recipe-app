#include "qt/main_window/MainWindow.h"

#include <QApplication>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w {};
    w.show();
    return a.exec();
}