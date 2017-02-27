#include "student.h"

/**
 * @brief Create a Student object.
 * @param a ID.
 * @param b First name.
 * @param c Last name.
 * @param d Picture location.
 */
Student::Student(QString a, QString b, QString c, QUrl d)
{
    id = a;
    fName = b;
    lName = c;
    picture = d;
    for (int i = 0; i < sizeof(isSpare); i++) {
        isSpare[i] = false;
    }
    for (int i = 0; i < sizeof(isSignedIn); i++) {
        isSignedIn[i] = false;
    }
}

/**
 * @return Student ID.
 */
QString Student::getId()
{
    return id;
}

/**
 * @return Student first name.
 */
QString Student::getFName()
{
    return fName;
}

/**
 * @return Student last name.
 */
QString Student::getLName()
{
    return lName;
}

/**
 * @return Student picture location.
 */
QUrl Student::getPicture()
{
    return picture;
}

/**
 * @param s Student first name.
 */
void Student::setFName(QString s)
{
    fName = s;
}

/**
 * @param s Student last name.
 */
void Student::setLName(QString s)
{
    lName = s;
}

/**
 * @param i Spare index.
 */
void Student::addSpare(int i)
{
    isSpare[i] = true;
}

/**
 * @param i Spare index.
 */
void Student::removeSpare(int i)
{
    isSpare[i] = false;
}

/**
 * @param i Spare index.
 */
bool Student::hasSpare(int i)
{
    return isSpare[i];
}

/**
 * @param i Spare index.
 */
void Student::signIn(int i)
{
    isSignedIn[i] = true;
}

/**
 * @param i Spare index.
 */
void Student::signOut(int i)
{
    isSignedIn[i] = false;
}

/**
 * @param i Spare index.
 */
bool Student::signedIn(int i)
{
    return isSignedIn[i];
}
