#include "studentio.h"

StudentIO::StudentIO()
{
    header = readHeader();
}

std::vector<std::string> StudentIO::readHeader()
{
    std::ifstream dayOneFileIn("data/day1.csv");
    std::string line;
    if (dayOneFileIn.is_open()) {
        std::getline(dayOneFileIn, line);
        dayOneFileIn.close();
    }
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string arg;
    while (ss >> arg) {
        result.push_back(arg);
        if (ss.peek() == ',')
            ss.ignore();
    }
}

std::vector<Student> StudentIO::readStudents()
{
    std::vector<Student> students;
    students.push_back(Student("123", "ABC", "DEF"));
    students.push_back(Student("321", "FED", "CBA"));
    return students;
}
