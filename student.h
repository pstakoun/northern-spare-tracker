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

private:
    QString id;
    QString fname;
    QString lname;
};

#endif // STUDENT_H
