#ifndef STUDENTIO_H
#define STUDENTIO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <QCoreApplication>
#include "student.h"

class StudentIO
{
public:
    StudentIO();
    std::vector<Student*> readStudents();
};

#endif // STUDENTIO_H
