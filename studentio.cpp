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

    for (int i = 0; i < sizeof(paths); i++) {
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

            Student *newStudent = NULL;

            foreach (Student *student, students) {
                if (student->getId().compare(QString::fromStdString(args[idIndex])) == 0) {
                    newStudent = student;
                    newStudent->addSpare(std::stoi(args[periodIndex]) + i * NUM_PERIODS - 1);
                    break;
                }
            }

            if (newStudent == NULL) {
                newStudent = new Student(QString::fromStdString(args[idIndex]),
                                             QString::fromStdString(args[fnameIndex]),
                                             QString::fromStdString(args[lnameIndex]),
                                             QUrl::fromLocalFile(QString::fromStdString(QCoreApplication::applicationDirPath().toStdString() + "/data/pictures/"+args[idIndex]+".BMP")));
                newStudent->addSpare(std::stoi(args[periodIndex]) + i * NUM_PERIODS - 1);
                students.push_back(newStudent);
            }

            args.clear();
        }
    }

    return students;
}

void StudentIO::uploadSpares(int day, QUrl url)
{
    if (!QDir("data").exists()) {
        QDir().mkdir("data");
    }

    QString path = QString::fromStdString("data/day"+std::to_string(day)+".csv");

    if (QFile::exists(path)) {
        QFile::remove(path);
    }

    QFile::copy(url.toLocalFile(), path);
}

void StudentIO::uploadPictures(QUrl url)
{
    // TODO
}

void StudentIO::logSignIn(Student *s)
{
    if (!QDir("data").exists()) {
        QDir().mkdir("data");
    }

    QFile file("data/log.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream out(&file);
    out << QDateTime::currentDateTime().toString() << "," << s->getId() << "\n";
}
