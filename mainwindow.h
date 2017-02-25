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
    static int period;
    static QString searchQuery;
    static int sortColumn;
    static Qt::SortOrder sortOrder;
    static StudentIO studentIO;
    static void init();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void editStudent(Student*);
    bool matchesQuery(Student*);

private slots:
    void handleCellChanged(int, int, int, int);
    void handleDoubleClick(int, int);
    void handleSort(int, Qt::SortOrder);
    void handlePeriodChanged(int);
    void handleSearch(QString);
    void importStudents();
    void newStudent();
    void update();
};

#endif // MAINWINDOW_H
