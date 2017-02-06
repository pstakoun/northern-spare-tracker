#include "importwindow.h"
#include "ui_importwindow.h"

ImportWindow::ImportWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImportWindow)
{
    ui->setupUi(this);
}

ImportWindow::~ImportWindow()
{
    delete ui;
}
