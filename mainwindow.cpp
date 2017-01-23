#include "mainwindow.h"
#include "ui_mainwindow.h"

std::vector<Student> MainWindow::students;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->studentTable->setColumnCount(4);
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
    update();
}

void MainWindow::addStudent(Student s)
{
    students.push_back(s);
    update();
}

void MainWindow::update()
{
    ui->studentTable->setRowCount(students.size());
    for (int i = 0; i < students.size(); i++) {
        ui->studentTable->setItem(i, 0, new QTableWidgetItem(students[i].getId()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
