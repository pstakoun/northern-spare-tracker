#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include "mainwindow.h"

class MainWindow;

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = 0);
    MainWindow *mainWindow;
    ~StudentWindow();
    void setStudent(Student*);

private slots:
    void cancel();
    void deleteStudent();
    void done();

private:
    Ui::StudentWindow *ui;
    Student *student;
};

#endif // STUDENTWINDOW_H
