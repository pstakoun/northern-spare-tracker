#include "mainwindow.h"
#include "ui_mainwindow.h"

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
   studentWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
