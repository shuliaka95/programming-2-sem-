#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"
#include <iostream>

class StudentList {
private:
    struct Node {
        Student data;
        Node* next;
        Node(const Student& s);
    };

    Node* head;

    void insertSorted(Node* newNode);

public:
    StudentList();
    ~StudentList();

    void addStudent(const Student& s);
    StudentList extractFailingStudents();
    void print(const std::string& title) const;
};

#endif