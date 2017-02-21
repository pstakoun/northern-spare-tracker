#ifndef STUDENTIO_H
#define STUDENTIO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <QCoreApplication>
#include <QUrl>
#include <QDir>
#include <QFile>
#include "student.h"

class StudentIO
{
public:
    StudentIO();
    std::vector<Student*> readStudents();
    void uploadSpares(int, QUrl);
    void uploadPictures(QUrl);
};

#endif // STUDENTIO_H
