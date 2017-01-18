#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <vector>
#include <student.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    std::vector<Student> students;
    students.push_back(Student("123")); // TODO
    mainWindow.setStudents(students);

    return app.exec();
}
