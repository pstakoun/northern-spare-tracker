#include "student.h"

QString id;
QString fname;
QString lname;
bool isSpare[8] = { false };

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

bool Student::addSpare(int i)
{
    isSpare[i] = true;
}

void Student::removeSpare(int i)
{
    isSpare[i] = false;
}
