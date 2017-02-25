#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include "mainwindow.h"
#include <QDropEvent>
#include <QMimeData>
#include <QUrl>

class MainWindow;

namespace Ui {
class ImportWindow;
}

class ImportWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImportWindow(QWidget *parent = 0);
    ~ImportWindow();

protected:
    void dropEvent(QDropEvent *ev);
    void dragEnterEvent(QDragEnterEvent *ev);

private:
    Ui::ImportWindow *ui;
    MainWindow *mainWindow;
    StudentIO studentIO;

private slots:
    void done();
};

#endif // IMPORTWINDOW_H
