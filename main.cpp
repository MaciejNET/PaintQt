#include <QApplication>
#include "main_window.h"

///Funkcja do uruchamiania aplikacji
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
