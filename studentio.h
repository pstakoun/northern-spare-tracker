#ifndef STUDENTREADER_H
#define STUDENTREADER_H

#include <vector>
#include "student.h"

class StudentIO
{
public:
    StudentIO();
    std::vector<Student> readStudents();
};

#endif // STUDENTREADER_H
