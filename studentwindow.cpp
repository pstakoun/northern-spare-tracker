#include "studentwindow.h"
#include "ui_studentwindow.h"

StudentWindow::StudentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
    ui->deleteButton->hide();
    connect(ui->id, SIGNAL(textChanged(QString)), this, SLOT(updateData(QString)));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteStudent()));
    connect(ui->doneButton, SIGNAL(clicked()), this, SLOT(done()));
}

void StudentWindow::setStudent(Student *s)
{
    ui->id->setText(s->getId());
    ui->fname->setText(s->getFName());
    ui->lname->setText(s->getLName());
    QCheckBox* spares[] = {ui->checkBoxA, ui->checkBoxB, ui->checkBoxC, ui->checkBoxD, ui->checkBoxE, ui->checkBoxF, ui->checkBoxG, ui->checkBoxH};
    for (int i = 0; i < 8; i++) {
        if (s->hasSpare(i)) {
            spares[i]->setChecked(true);
        }
    }
    ui->deleteButton->show();
}

void StudentWindow::clearData()
{
    ui->fname->setText("");
    ui->lname->setText("");
    QCheckBox* spares[] = {ui->checkBoxA, ui->checkBoxB, ui->checkBoxC, ui->checkBoxD, ui->checkBoxE, ui->checkBoxF, ui->checkBoxG, ui->checkBoxH};
    for (int i = 0; i < 8; i++) {
        spares[i]->setChecked(false);
    }
    ui->deleteButton->hide();
}

void StudentWindow::updateData(QString id)
{
    Student* s = MainWindow::studentIO.getStudentById(id);
    if (s != nullptr) {
        setStudent(s);
    } else {
        clearData();
    }
}

void StudentWindow::cancel()
{
    setCentralWidget(new MainWindow);
}

void StudentWindow::deleteStudent()
{
    setCentralWidget(new MainWindow);
}

void StudentWindow::done()
{
    setCentralWidget(new MainWindow);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}
