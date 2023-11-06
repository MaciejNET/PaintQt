#include <QApplication>
#include "../include/main_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
