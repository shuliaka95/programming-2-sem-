#include "StudentList.h"
#include <iostream>

StudentList::Node::Node(const Student& s)
    : data(s), next(nullptr) {
}

StudentList::StudentList() : head(nullptr) {}

StudentList::~StudentList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void StudentList::insertSorted(Node* newNode) {
    if (!head || newNode->data.fio < head->data.fio) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data.fio < newNode->data.fio) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void StudentList::addStudent(const Student& s) {
    Node* newNode = new Node(s);
    insertSorted(newNode);
}

StudentList StudentList::extractFailingStudents() {
    StudentList failingList;
    Node** curr = &head;

    while (*curr) {
        if ((*curr)->data.averageScore < 3.0) {
            Node* toRemove = *curr;
            *curr = toRemove->next;

            failingList.addStudent(toRemove->data);
            delete toRemove;
        }
        else {
            curr = &((*curr)->next);
        }
    }

    return failingList;
}

void StudentList::print(const std::string& title) const {
    std::cout << title << ":\n";
    Node* current = head;
    while (current) {
        std::cout << current->data.fio
            << " (Курс: " << current->data.course
            << ", Средний балл: " << current->data.averageScore << ")\n";
        current = current->next;
    }
    std::cout << std::endl;
}