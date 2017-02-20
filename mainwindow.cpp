#include "mainwindow.h"
#include "ui_mainwindow.h"

std::vector<Student*> MainWindow::students;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->studentTable->setColumnCount(4);
    ui->studentTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->studentTable->setHorizontalHeaderItem(1, new QTableWidgetItem("First Name"));
    ui->studentTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Last Name"));
    ui->studentTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Sign In"));
    ui->studentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->studentTable->setSelectionMode(QAbstractItemView::NoSelection);
    ui->studentTable->setSortingEnabled(true);
    connect(ui->studentTable, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(handleDoubleClick(int, int)));
    connect(ui->addStudentButton, SIGNAL(clicked()), this, SLOT(newStudent()));
    connect(ui->importStudentsButton, SIGNAL(clicked()), this, SLOT(importStudents()));
    connect(ui->periodComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(update(int)));
    setStudents(studentIO.readStudents());
}

void MainWindow::handleDoubleClick(int row, int col)
{
    // TODO
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

void MainWindow::editStudent()
{
   studentWindow = new StudentWindow;
   studentWindow->setStudent(students[0]); // TODO get correct student
   setCentralWidget(studentWindow);
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
    if (ui->periodComboBox->currentIndex() != 0) {
        update(ui->periodComboBox->currentIndex());
        return;
    }
    ui->studentTable->setSortingEnabled(false);
    ui->studentTable->setRowCount(students.size());
    for (int i = 0; i < students.size(); i++) {
        ui->studentTable->setItem(i, 0, new QTableWidgetItem(students[i]->getId()));
        ui->studentTable->setItem(i, 1, new QTableWidgetItem(students[i]->getFName()));
        ui->studentTable->setItem(i, 2, new QTableWidgetItem(students[i]->getLName()));
    }
    ui->studentTable->setSortingEnabled(true);
}

void MainWindow::update(int period)
{
    ui->studentTable->setSortingEnabled(false);
    ui->studentTable->setRowCount(0);

    if (period == 0) {
        update();
        return;
    }
    period -= 1;

    int numStudents = 0;
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->hasSpare(period)) {
            numStudents++;
        }
    }

    ui->studentTable->setRowCount(numStudents);
    for (int i = 0, currentIndex = 0; currentIndex < numStudents; i++) {
        if (students[i]->hasSpare(period)) {
            ui->studentTable->setItem(currentIndex, 0, new QTableWidgetItem(students[i]->getId()));
            ui->studentTable->setItem(currentIndex, 1, new QTableWidgetItem(students[i]->getFName()));
            ui->studentTable->setItem(currentIndex, 2, new QTableWidgetItem(students[i]->getLName()));
            currentIndex++;
        }
    }
    ui->studentTable->setSortingEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
