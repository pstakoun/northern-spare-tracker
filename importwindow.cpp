#include "importwindow.h"
#include "ui_importwindow.h"

ImportWindow::ImportWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImportWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

void ImportWindow::dropEvent(QDropEvent *ev)
{
    QList<QUrl> urls = ev->mimeData()->urls();
    foreach(QUrl url, urls)
    {
        switch(ui->importTypeComboBox->currentIndex()) {
            case 1:
                studentIO.uploadSpares(1, url);
                break;
            case 2:
                studentIO.uploadSpares(1, url);
                break;
            case 3:
                studentIO.uploadPictures(url);
        }
    }
}

void ImportWindow::dragEnterEvent(QDragEnterEvent *ev)
{
    ev->accept();
}

ImportWindow::~ImportWindow()
{
    delete ui;
}
