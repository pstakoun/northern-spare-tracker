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
    ui->label->setText("Importing...");
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
                studentIO.uploadPicture(url);
        }
    }
    ui->label->setText("Done");
}

void ImportWindow::dragEnterEvent(QDragEnterEvent *ev)
{
    ui->label->setText("Drop to Import");
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
