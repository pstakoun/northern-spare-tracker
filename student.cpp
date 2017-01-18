#include "student.h"

QString id;

Student::Student(QString a)
{
    id = a;
}

QString Student::getId()
{
    return id;
}
