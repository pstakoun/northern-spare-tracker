#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <vector>
#include "student.h"
#include "studentio.h"
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
    void setStudents(std::vector<Student*>);
    void addStudent(Student*);
    void update();
    ~MainWindow();

private slots:
    void newStudent();
    void editStudent();
    void importStudents();
    void update(int);

private:
    Ui::MainWindow *ui;
    StudentIO studentIO;
    StudentWindow *studentWindow;
    ImportWindow *importWindow;
    static std::vector<Student*> students;
};

#endif // MAINWINDOW_H
