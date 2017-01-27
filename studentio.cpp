#include "studentio.h"

StudentIO::StudentIO()
{
    header = readHeader();
}

static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

std::vector<std::string> StudentIO::readHeader()
{
    std::ifstream fileIn;
    fileIn.open(QCoreApplication::applicationDirPath().toStdString() + "/data/day1.csv");
    std::string line;
    if (fileIn.is_open()) {
        std::getline(fileIn, line);
        fileIn.close();
    }
    std::vector<std::string> result;
    std::istringstream ss(rtrim(line));
    std::string token;
    while(std::getline(ss, token, ',')) {
        result.push_back(token);
    }
    return result;
}

std::vector<Student> StudentIO::readStudents()
{
    int idIndex = -1, fnameIndex = -1, lnameIndex = -1;
    for (int i = 0; i < header.size(); i++) {
        if ("student_no" == header[i])
            idIndex = i;
        else if ("preferred_first_name" == header[i])
            fnameIndex = i;
        else if ("preferred_surname" == header[i])
            lnameIndex = i;
    }
    std::vector<Student> students;
    students.push_back(Student(QString::number(idIndex), QString::number(fnameIndex), QString::number(lnameIndex)));
    return students;
}
