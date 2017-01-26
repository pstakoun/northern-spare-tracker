#ifndef STUDENTREADER_H
#define STUDENTREADER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "student.h"

class StudentIO
{
public:
    StudentIO();
    std::vector<std::string> readHeader();
    std::vector<Student> readStudents();

private:
    std::vector<std::string> header;
    std::ifstream dayOneFileIn;
    std::ifstream dayTwoFileIn;
    std::ifstream customFileIn;
    std::ofstream dayOneFileOut;
    std::ofstream dayTwoFileOut;
    std::ofstream customFileOut;
};

#endif // STUDENTREADER_H
