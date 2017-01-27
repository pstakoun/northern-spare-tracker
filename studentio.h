#ifndef STUDENTREADER_H
#define STUDENTREADER_H

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
    std::vector<std::string> readHeader();
    std::vector<Student> readStudents();

private:
    std::vector<std::string> header;
};

#endif // STUDENTREADER_H
