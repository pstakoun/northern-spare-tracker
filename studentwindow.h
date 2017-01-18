#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
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

private slots:
    void cancel();
    void done();

private:
    Ui::StudentWindow *ui;
};

#endif // STUDENTWINDOW_H
