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
    connect(ui->search, SIGNAL(textChanged(QString)), this, SLOT(handleSearch(QString)));
    setStudents(studentIO.readStudents());
}

void MainWindow::handleDoubleClick(int row, int col)
{
    QString id = ui->studentTable->item(row, 0)->text();
    Student *s;
    for (int i = 0; i < students.size(); i++) {
        if (id == students[i]->getId()) {
            s = students[i];
            break;
        }
    }

    if (col == ui->studentTable->columnCount() - 1) {
        int period = ui->periodComboBox->currentIndex();

        if (s->signedIn(period)) {
            s->signOut(period);
            ui->studentTable->setItem(row, col, new QTableWidgetItem(""));
        } else {
            s->signIn(period);
            studentIO.logSignIn(s);
            ui->studentTable->setItem(row, col, new QTableWidgetItem("Signed In"));
        }
    } else {
        editStudent(s);
    }
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

void MainWindow::editStudent(Student *s)
{
   studentWindow = new StudentWindow;
   studentWindow->setStudent(s);
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

bool MainWindow::matchesQuery(Student *s)
{
    if (s->getId().startsWith(searchQuery) || s->getFName().startsWith(searchQuery, Qt::CaseInsensitive) || s->getLName().startsWith(searchQuery, Qt::CaseInsensitive)) {
        return true;
    }
    return false;
}

void MainWindow::update()
{
    update(ui->periodComboBox->currentIndex());
}

void MainWindow::update(int period)
{
    ui->studentTable->setSortingEnabled(false);
    ui->studentTable->setRowCount(0);

    int numStudents = 0;
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->hasSpare(period) && matchesQuery(students[i])) {
            numStudents++;
        }
    }

    ui->studentTable->setRowCount(numStudents);
    for (int i = 0, currentIndex = 0; currentIndex < numStudents; i++) {
        if (students[i]->hasSpare(period) && matchesQuery(students[i])) {
            ui->studentTable->setItem(currentIndex, 0, new QTableWidgetItem(students[i]->getId()));
            ui->studentTable->setItem(currentIndex, 1, new QTableWidgetItem(students[i]->getFName()));
            ui->studentTable->setItem(currentIndex, 2, new QTableWidgetItem(students[i]->getLName()));
            if (students[i]->signedIn(period)) {
                ui->studentTable->setItem(currentIndex, 3, new QTableWidgetItem("Signed In"));
            }
            currentIndex++;
        }
    }
    ui->studentTable->setSortingEnabled(true);
}

void MainWindow::handleSearch(QString query)
{
    searchQuery = query;
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
