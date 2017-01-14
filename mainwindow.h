#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    ~MainWindow();

private slots:
    void newStudent();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
