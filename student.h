#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

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
    bool isSpare[8];
};

#endif // STUDENT_H
