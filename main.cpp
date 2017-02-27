#include "mainwindow.h"
#include <QApplication>

/**
 * @brief Main entry point for Northern Spare Tracker.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow::init();

    MainWindow mainWindow;

    mainWindow.show();

    return app.exec();
}
