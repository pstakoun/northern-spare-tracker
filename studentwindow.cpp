#include "studentwindow.h"
#include "ui_studentwindow.h"

/**
 * @brief Initialize Student GUI.
 * @param parent
 */
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

/**
 * @brief Initialize GUI with Student data.
 * @param s Student object.
 */
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

/**
 * @brief Clear data from GUI.
 */
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

/**
 * @brief Update GUI with Student data.
 * @param id Student ID.
 */
void StudentWindow::updateData(QString id)
{
    Student* s = MainWindow::studentIO.getStudentById(id);
    if (s != nullptr) {
        setStudent(s);
    } else {
        clearData();
    }
}

/**
 * @brief Return to Main GUI.
 */
void StudentWindow::cancel()
{
    setCentralWidget(new MainWindow);
}

/**
 * @brief Delete Student object from input data.
 */
void StudentWindow::deleteStudent()
{
    MainWindow::studentIO.removeStudentById(ui->id->text());
    MainWindow::studentIO.writeStudents();
    cancel();
}

/**
 * @brief Update Student object with input data.
 */
void StudentWindow::done()
{
    Student *student = MainWindow::studentIO.getStudentById(ui->id->text());

    if (student == nullptr) {
        student = new Student(ui->id->text(), ui->fname->text(), ui->lname->text(), QUrl::fromLocalFile(QString::fromStdString(QCoreApplication::applicationDirPath().toStdString() + "/data/pictures/" + ui->id->text().toStdString() + ".BMP")));
        MainWindow::studentIO.addStudent(student);
    } else {
        student->setFName(ui->fname->text());
        student->setLName(ui->lname->text());
    }

    QCheckBox* checkBoxes[] = {ui->checkBoxA, ui->checkBoxB, ui->checkBoxC, ui->checkBoxD, ui->checkBoxE, ui->checkBoxF, ui->checkBoxG, ui->checkBoxH};
    for (int i = 0; i < 8; i++) {
        if (checkBoxes[i]->isChecked()) student->addSpare(i);
        else student->removeSpare(i);
    }

    MainWindow::studentIO.writeStudents();
    cancel();
}

/**
 * @brief Delete Student GUI.
 */
StudentWindow::~StudentWindow()
{
    delete ui;
}
