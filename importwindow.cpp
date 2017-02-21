#include "importwindow.h"
#include "ui_importwindow.h"

ImportWindow::ImportWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImportWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    connect(ui->doneButton, SIGNAL(clicked()), this, SLOT(done()));
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
                studentIO.uploadSpares(2, url);
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

void ImportWindow::done()
{
    mainWindow = new MainWindow;
    mainWindow->update();
    setCentralWidget(mainWindow);
}

ImportWindow::~ImportWindow()
{
    delete ui;
}
