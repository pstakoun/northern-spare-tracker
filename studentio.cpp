#include "studentio.h"

/**
 * @brief Trim whitespace from string.
 * @param s Initial string.
 * @return String without whitespace.
 */
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

/**
 * @brief Read Students from data files to vector.
 */
void StudentIO::readStudents()
{
    students.clear();

    std::string paths[] = {QCoreApplication::applicationDirPath().toStdString() + "/data/day1.csv", QCoreApplication::applicationDirPath().toStdString() + "/data/day2.csv"};

    for (int i = 0; i < 2; i++) {
        std::string path = paths[i];
        std::ifstream fileIn;
        fileIn.open(path);
        if (!fileIn.is_open()) return;

        std::string line;
        std::getline(fileIn, line);
        std::vector<std::string> header;
        std::istringstream ss(rtrim(line));
        std::string token;
        while(std::getline(ss, token, ',')) header.push_back(token);

        int idIndex = -1, fnameIndex = -1, lnameIndex = -1, periodIndex = -1;
        for (int i = 0; i < header.size(); i++) {
            if ("student_no" == header[i]) idIndex = i;
            else if ("preferred_first_name" == header[i]) fnameIndex = i;
            else if ("preferred_surname" == header[i]) lnameIndex = i;
            else if ("school_period" == header[i]) periodIndex = i;
        }
        if (idIndex == -1 || fnameIndex == -1 || lnameIndex == -1 || periodIndex == -1) return;

        std::vector<std::string> args;
        while (std::getline(fileIn, line)) {
            std::istringstream ss(rtrim(line));
            std::string token;
            while(std::getline(ss, token, ',')) args.push_back(token);

            Student *newStudent = NULL;
            foreach (Student *student, students) {
                if (student->getId().compare(QString::fromStdString(args[idIndex])) == 0) {
                    newStudent = student;
                    newStudent->addSpare(std::stoi(args[periodIndex]) + i * NUM_PERIODS - 1);
                    break;
                }
            }

            if (newStudent == NULL) {
                newStudent = new Student(QString::fromStdString(args[idIndex]), QString::fromStdString(args[fnameIndex]), QString::fromStdString(args[lnameIndex]), QUrl::fromLocalFile(QString::fromStdString(QCoreApplication::applicationDirPath().toStdString() + "/data/pictures/"+args[idIndex]+".BMP")));
                newStudent->addSpare(std::stoi(args[periodIndex]) + i * NUM_PERIODS - 1);
                students.push_back(newStudent);
            }

            args.clear();
        }

        fileIn.close();
    }
}

/**
 * @brief Write Students from vector to data files.
 */
void StudentIO::writeStudents()
{
    std::string paths[] = {QCoreApplication::applicationDirPath().toStdString() + "/data/day1.csv", QCoreApplication::applicationDirPath().toStdString() + "/data/day2.csv"};

    for (int i = 0; i < 2; i++) {
        std::string path = paths[i];
        std::ofstream fileOut;
        fileOut.open(path);
        if (!fileOut.is_open()) return;

        fileOut << "school_period,preferred_first_name,preferred_surname,student_no\n";

        foreach (Student *student, students)
            for (int period = NUM_PERIODS*i; period < NUM_PERIODS*(i+1); period++)
                if (student->hasSpare(period))
                    fileOut << std::to_string(period-NUM_PERIODS*i+1) << "," << student->getFName().toStdString() << "," << student->getLName().toStdString() << "," << student->getId().toStdString() << "\n";

        fileOut.close();
    }
}

/**
 * @return Student data.
 */
std::vector<Student*> StudentIO::getStudents()
{
    return students;
}

/**
 * @return Student with matching ID.
 */
Student* StudentIO::getStudentById(QString id)
{
    for (int i = 0; i < students.size(); i++)
        if (id == students[i]->getId())
            return students[i];
    return nullptr;
}

/**
 * @param id Student ID.
 */
void StudentIO::removeStudentById(QString id)
{
    for (int i = 0; i < students.size(); i++) {
        if (id == students[i]->getId()) {
            students.erase(students.begin()+i);
            return;
        }
    }
}

/**
 * @param student Student object.
 */
void StudentIO::addStudent(Student *student)
{
    if (getStudentById(student->getId()) == nullptr)
        students.push_back(student);
}

/**
 * @brief Copy local data files to application directory.
 * @param day Data file day.
 * @param url Data file location.
 */
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

/**
 * @brief Copy local picture file to application directory.
 * @param url Picture location.
 */
void StudentIO::uploadPicture(QUrl url)
{
    if (!QDir("data/pictures").exists()) {
        QDir().mkdir("data/pictures");
    }

    QString path = "data/pictures/"+url.fileName();

    if (QFile::exists(path)) {
        QFile::remove(path);
    }

    QFile::copy(url.toLocalFile(), path);
}

/**
 * @brief Log Student sign in to file.
 * @param s Student object.
 */
void StudentIO::logSignIn(Student *s)
{
    if (!QDir("data").exists()) {
        QDir().mkdir("data");
    }

    QFile file("data/log.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream out(&file);
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") << "," << s->getId() << "," << s->getFName() << "," << s->getLName() << "\n";
}
