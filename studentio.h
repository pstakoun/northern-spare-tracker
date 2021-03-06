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
#include <QTextStream>
#include <QDateTime>
#include "student.h"

class StudentIO
{

public:
    void readStudents();
    void writeStudents();
    std::vector<Student*> getStudents();
    Student* getStudentById(QString);
    void removeStudentById(QString);
    void addStudent(Student*);
    void uploadSpares(int, QUrl);
    void uploadPicture(QUrl);
    void logSignIn(Student*);

private:
    std::vector<Student*> students;
};

#endif // STUDENTIO_H
