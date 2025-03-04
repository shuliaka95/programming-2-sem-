#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string fio;
    std::string birthDate;
    int course;
    double averageScore; // ������������ (������� ����)

    Student(const std::string& f, const std::string& bd, int c, double avg);
};

#endif