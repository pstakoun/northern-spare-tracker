#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "student.h"
#include "studentwindow.h"

class StudentWindow;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    StudentWindow *studentWindow;
    void setStudents(std::vector<Student>);
    void addStudent(Student);
    void update();
    ~MainWindow();

private slots:
    void newStudent();

private:
    Ui::MainWindow *ui;
    static std::vector<Student> students;
};

#endif // MAINWINDOW_H
