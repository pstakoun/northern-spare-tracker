#include "studentio.h"

StudentIO::StudentIO()
{

}

std::vector<Student> StudentIO::readStudents()
{
    std::vector<Student> students;
    students.push_back(Student("123", "ABC", "DEF"));
    students.push_back(Student("321", "FED", "CBA"));
    return students;
}
