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

private:
    Ui::StudentWindow *ui;
    Student *student;
    void clearData();

private slots:
    void updateData(QString);
    void cancel();
    void deleteStudent();
    void done();
};

#endif // STUDENTWINDOW_H
