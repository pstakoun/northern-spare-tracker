#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student(QString);
    QString getId();

private:
    QString id;
    QString fname;
    QString lname;
};

#endif // STUDENT_H
