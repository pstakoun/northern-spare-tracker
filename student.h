#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

static const int NUM_PERIODS = 4;
static const int NUM_DAYS = 2;

class Student
{
public:
    Student(QString, QString, QString);
    QString getId();
    QString getFName();
    QString getLName();
    void addSpare(int);
    void removeSpare(int);
    bool hasSpare(int);

private:
    QString id;
    QString fname;
    QString lname;
    bool isSpare[NUM_PERIODS * NUM_DAYS];
};

#endif // STUDENT_H
