#include "importwindow.h"
#include "ui_importwindow.h"

/**
 * @brief Initialize Import GUI.
 * @param parent
 */
ImportWindow::ImportWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImportWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    connect(ui->doneButton, SIGNAL(clicked()), this, SLOT(done()));
}

/**
 * @brief Handle file drop event.
 * @param ev
 */
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

/**
 * @brief Handle file drag event.
 * @param ev
 */
void ImportWindow::dragEnterEvent(QDragEnterEvent *ev)
{
    ui->label->setText("Drop to Import");
    ev->accept();
}

/**
 * @brief Return to Main GUI.
 */
void ImportWindow::done()
{
    setCentralWidget(new MainWindow);
}

/**
 * @brief Delete Import GUI.
 */
ImportWindow::~ImportWindow()
{
    delete ui;
}
