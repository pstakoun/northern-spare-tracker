#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow::init();

    MainWindow mainWindow;

    mainWindow.show();

    return app.exec();
}
