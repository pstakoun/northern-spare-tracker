#include "mainwindow.h"
#include "ui_mainwindow.h"

std::vector<Student> MainWindow::students;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newStudentButton, SIGNAL(clicked()), this, SLOT(newStudent()));
}

void MainWindow::newStudent()
{
   studentWindow = new StudentWindow;
   setCentralWidget(studentWindow);
}

void MainWindow::setStudents(std::vector<Student> s)
{
    students = s;
    ui->studentTable->setRowCount(1);
    ui->studentTable->setColumnCount(1);
    ui->studentTable->setItem(0, 0, new QTableWidgetItem(students[0].getId()));
}

void MainWindow::update()
{
    ui->studentTable->setRowCount(1);
    ui->studentTable->setColumnCount(1);
    ui->studentTable->setItem(0, 0, new QTableWidgetItem(students[0].getId()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
