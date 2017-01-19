#include "mainwindow.h"
#include "studentio.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    StudentIO studentIO;

    mainWindow.show();

    mainWindow.setStudents(studentIO.readStudents());

    return app.exec();
}
