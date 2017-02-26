#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::period;
QString MainWindow::searchQuery;
int MainWindow::sortColumn;
Qt::SortOrder MainWindow::sortOrder;
StudentIO MainWindow::studentIO;

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

    connect(ui->studentTable, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(handleCellChanged(int, int, int, int)));
    connect(ui->studentTable, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(handleDoubleClick(int, int)));
    connect(ui->studentTable->horizontalHeader(), SIGNAL(sortIndicatorChanged(int, Qt::SortOrder)), this, SLOT(handleSort(int, Qt::SortOrder)));
    connect(ui->addStudentButton, SIGNAL(clicked()), this, SLOT(newStudent()));
    connect(ui->importStudentsButton, SIGNAL(clicked()), this, SLOT(importStudents()));
    connect(ui->periodComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handlePeriodChanged(int)));
    connect(ui->search, SIGNAL(textChanged(QString)), this, SLOT(handleSearch(QString)));

    ui->periodComboBox->setCurrentIndex(period);
    ui->search->setText(searchQuery);
    ui->studentTable->sortByColumn(sortColumn, sortOrder);

    studentIO.readStudents();
    update();
}

void MainWindow::init() {
    MainWindow::period = 0;
    MainWindow::searchQuery = "";
    MainWindow::sortColumn = 0;
    MainWindow::sortOrder = Qt::AscendingOrder;
    MainWindow::studentIO = StudentIO();
}

void MainWindow::handleCellChanged(int row, int col, int prevRow, int prevCol)
{
    if (row == -1 || col == -1) {
        ui->picture->setPixmap(QPixmap());
        return;
    }

    QString id = ui->studentTable->item(row, 0)->text();
    Student *s = studentIO.getStudentById(id);

    ui->picture->setPixmap(QPixmap(s->getPicture().toLocalFile()));
}

void MainWindow::handleDoubleClick(int row, int col)
{
    QString id = ui->studentTable->item(row, 0)->text();
    Student *s = studentIO.getStudentById(id);

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

void MainWindow::handleSort(int column, Qt::SortOrder order)
{
    sortColumn = column;
    sortOrder = order;
}

void MainWindow::handlePeriodChanged(int p)
{
    period = p;
    update();
}

void MainWindow::handleSearch(QString query)
{
    searchQuery = query;
    update();
}

void MainWindow::importStudents()
{
   setCentralWidget(new ImportWindow);
}

void MainWindow::newStudent()
{
   setCentralWidget(new StudentWindow);
}

void MainWindow::editStudent(Student *s)
{
   StudentWindow *studentWindow = new StudentWindow;
   studentWindow->setStudent(s);
   setCentralWidget(studentWindow);
}

bool MainWindow::matchesQuery(Student *s)
{
    QStringList searchArr = searchQuery.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    if (searchArr.size() == 0) return true;
    for (QString str : searchQuery.split(QRegExp("\\s+"), QString::SkipEmptyParts)) {
        if (!(s->getId().startsWith(str) || s->getFName().startsWith(str, Qt::CaseInsensitive) || s->getLName().startsWith(str, Qt::CaseInsensitive))) {
            return false;
        }
    }
    return true;
}

void MainWindow::update()
{
    ui->studentTable->setSortingEnabled(false);
    ui->studentTable->setRowCount(0);

    std::vector<Student*> students = studentIO.getStudents();
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

MainWindow::~MainWindow()
{
    delete ui;
}
