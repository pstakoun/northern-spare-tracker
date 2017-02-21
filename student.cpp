#include "student.h"

Student::Student(QString a, QString b, QString c, QUrl d)
{
    id = a;
    fName = b;
    lName = c;
    picture = d;
    for (int i = 0; i < sizeof(isSpare); i++) {
        isSpare[i] = false;
    }
}

QString Student::getId()
{
    return id;
}

QString Student::getFName()
{
    return fName;
}

QString Student::getLName()
{
    return lName;
}

QUrl Student::getPicture()
{
    return picture;
}

void Student::addSpare(int i)
{
    isSpare[i] = true;
}

void Student::removeSpare(int i)
{
    isSpare[i] = false;
}

bool Student::hasSpare(int i)
{
    return isSpare[i];
}

void Student::signIn(int i)
{
    isSignedIn[i] = true;
}

void Student::signOut(int i)
{
    isSignedIn[i] = false;
}

bool Student::signedIn(int i)
{
    return isSignedIn[i];
}
