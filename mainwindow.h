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
    static void init();
    void setStudents(std::vector<Student*>);
    void addStudent(Student*);
    ~MainWindow();

private slots:
    void handleCellChanged(int, int, int, int);
    void handleDoubleClick(int, int);
    void handleSort(int, Qt::SortOrder);
    void newStudent();
    void importStudents();
    void update();
    void handlePeriodChanged(int);
    void handleSearch(QString);

private:
    Ui::MainWindow *ui;
    StudentIO studentIO;
    StudentWindow *studentWindow;
    ImportWindow *importWindow;
    std::vector<Student*> students;
    void editStudent(Student*);
    bool matchesQuery(Student*);
};

#endif // MAINWINDOW_H
