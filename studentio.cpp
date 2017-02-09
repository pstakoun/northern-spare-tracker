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
    std::string paths[] = {QCoreApplication::applicationDirPath().toStdString() + "/data/day1.csv",
                           QCoreApplication::applicationDirPath().toStdString() + "/data/day2.csv"};

    std::vector<Student*> students;

    for (int i = 0; i < paths.length; i++) {
        std::string path = paths[i];

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

        int idIndex = -1, fnameIndex = -1, lnameIndex = -1, periodIndex = -1;
        for (int i = 0; i < header.size(); i++) {
            if ("student_no" == header[i])
                idIndex = i;
            else if ("preferred_first_name" == header[i])
                fnameIndex = i;
            else if ("preferred_surname" == header[i])
                lnameIndex = i;
            else if ("school_period" == header[i])
                periodIndex = i;
        }

        if (idIndex == -1 || fnameIndex == -1 || lnameIndex == -1 || periodIndex == -1)
            return students;

        std::vector<std::string> args;
        while (std::getline(fileIn, line)) {
            std::istringstream ss(rtrim(line));
            std::string token;
            while(std::getline(ss, token, ',')) {
                args.push_back(token);
            }
            // TODO find and modify student with ID if exists
            Student newStudent = new Student(QString::fromStdString(args[idIndex]),
                                             QString::fromStdString(args[fnameIndex]),
                                             QString::fromStdString(args[lnameIndex]));
            newStudent.addSpare(std::stoi(args[periodIndex]) + i * 4 - 1);
            students.push_back(newStudent);
            args.clear();
        }
    }

    return students;
}

void StudentIO::uploadFile(QUrl url)
{

}
