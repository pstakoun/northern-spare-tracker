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

void StudentWindow::cancel()
{
    mainWindow = new MainWindow;
    setCentralWidget(mainWindow);
}

void StudentWindow::done()
{
    mainWindow = new MainWindow;
    setCentralWidget(mainWindow);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}
