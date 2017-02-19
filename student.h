#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QUrl>

static const int NUM_PERIODS = 4;
static const int NUM_DAYS = 2;

class Student
{
public:
    Student(QString, QString, QString);
    QString getId();
    QString getFName();
    QString getLName();
    QUrl getPicture();
    void addSpare(int);
    void removeSpare(int);
    bool hasSpare(int);

private:
    QString id;
    QString fName;
    QString lName;
    QUrl picture;
    bool isSpare[NUM_PERIODS * NUM_DAYS];
};

#endif // STUDENT_H
