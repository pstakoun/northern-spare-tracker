#include "student.h"

QString id;
QString fname;
QString lname;

Student::Student(QString a, QString b, QString c)
{
    id = a;
    fname = b;
    lname = c;
}

QString Student::getId()
{
    return id;
}

QString Student::getFName()
{
    return fname;
}

QString Student::getLName()
{
    return lname;
}
