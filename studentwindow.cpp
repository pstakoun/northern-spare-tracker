#include "studentwindow.h"
#include "ui_studentwindow.h"

StudentWindow::StudentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
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
    loadPicture();
}

void StudentWindow::loadPicture()
{
    QPixmap p(student->getPicture().toLocalFile());
    ui->picture->setPixmap(p);
}

void StudentWindow::cancel()
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
