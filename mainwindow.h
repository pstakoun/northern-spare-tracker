#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "student.h"
#include "studentwindow.h"
#include "importwindow.h"

class StudentWindow;
class ImportWindow;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    StudentWindow *studentWindow;
    ImportWindow *importWindow;
    void setStudents(std::vector<Student*>);
    void addStudent(Student*);
    void update();
    ~MainWindow();

private slots:
    void newStudent();
    void importStudents();

private:
    Ui::MainWindow *ui;
    static std::vector<Student*> students;
};

#endif // MAINWINDOW_H
