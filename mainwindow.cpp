#include "mainwindow.h"
#include "ui_mainwindow.h"

std::vector<Student*> MainWindow::students;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->studentTable->setColumnCount(3);
    ui->studentTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->studentTable->setHorizontalHeaderItem(1, new QTableWidgetItem("First Name"));
    ui->studentTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Last Name"));
    ui->studentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->studentTable->setSelectionMode(QAbstractItemView::NoSelection);
    ui->studentTable->setSortingEnabled(true);
    connect(ui->importStudentsButton, SIGNAL(clicked()), this, SLOT(importStudents()));
    connect(ui->addStudentButton, SIGNAL(clicked()), this, SLOT(newStudent()));
    setStudents(studentIO.readStudents());
}

void MainWindow::newStudent()
{
   studentWindow = new StudentWindow;
   setCentralWidget(studentWindow);
}

void MainWindow::importStudents()
{
   importWindow = new ImportWindow;
   setCentralWidget(importWindow);
}

void MainWindow::setStudents(std::vector<Student*> s)
{
    students = s;
    update();
}

void MainWindow::addStudent(Student *s)
{
    students.push_back(s);
    update();
}

void MainWindow::update()
{
    ui->studentTable->setRowCount(students.size());
    for (int i = 0; i < students.size(); i++) {
        ui->studentTable->setItem(i, 0, new QTableWidgetItem(students[i]->getId()));
        ui->studentTable->setItem(i, 1, new QTableWidgetItem(students[i]->getFName()));
        ui->studentTable->setItem(i, 2, new QTableWidgetItem(students[i]->getLName()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
