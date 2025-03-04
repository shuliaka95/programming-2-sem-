#include "Student.h"

Student::Student(const std::string& f, const std::string& bd, int c, double avg)
    : fio(f), birthDate(bd), course(c), averageScore(avg) {
}