#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include "mainwindow.h"

class MainWindow;

namespace Ui {
class ImportWindow;
}

class ImportWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImportWindow(QWidget *parent = 0);
    MainWindow *mainWindow;
    ~ImportWindow();

private:
    Ui::ImportWindow *ui;
};

#endif // IMPORTWINDOW_H
