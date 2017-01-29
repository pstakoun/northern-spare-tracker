#include "studentio.h"

StudentIO::StudentIO()
{

}

static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

std::vector<Student*> StudentIO::readStudents()
{
    std::string path = QCoreApplication::applicationDirPath().toStdString() + "/data/day1.csv";

    std::vector<Student*> students;

    std::ifstream fileIn;
    fileIn.open(path);

    if (!fileIn.is_open())
        return students;

    std::string line;

    std::getline(fileIn, line);

    std::vector<std::string> header;
    std::istringstream ss(rtrim(line));
    std::string token;
    while(std::getline(ss, token, ',')) {
        header.push_back(token);
    }

    int idIndex = -1, fnameIndex = -1, lnameIndex = -1;
    for (int i = 0; i < header.size(); i++) {
        if ("student_no" == header[i])
            idIndex = i;
        else if ("preferred_first_name" == header[i])
            fnameIndex = i;
        else if ("preferred_surname" == header[i])
            lnameIndex = i;
    }

    if (idIndex == -1 || fnameIndex == -1 || lnameIndex == -1)
        return students;

    std::vector<std::string> args;
    while (std::getline(fileIn, line)) {
        std::istringstream ss(rtrim(line));
        std::string token;
        while(std::getline(ss, token, ',')) {
            args.push_back(token);
        }
        students.push_back(new Student(QString::fromStdString(args[idIndex]), QString::fromStdString(args[fnameIndex]), QString::fromStdString(args[lnameIndex])));
        args.clear();
    }

    return students;
}
