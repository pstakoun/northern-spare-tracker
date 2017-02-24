#include "studentwindow.h"
#include "ui_studentwindow.h"

StudentWindow::StudentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
    ui->deleteButton->hide();
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteStudent()));
    connect(ui->doneButton, SIGNAL(clicked()), this, SLOT(done()));
}

void StudentWindow::setStudent(Student *s)
{
    student = s;
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

void StudentWindow::cancel()
{
    mainWindow = new MainWindow;
    mainWindow->update();
    setCentralWidget(mainWindow);
}

void StudentWindow::deleteStudent()
{
    mainWindow = new MainWindow;
    mainWindow->update();
    setCentralWidget(mainWindow);
}

void StudentWindow::done()
{
    mainWindow = new MainWindow;
    mainWindow->update();
    setCentralWidget(mainWindow);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}
