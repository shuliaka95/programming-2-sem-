#include "mylist.h"
#include <iostream>

// ����������� ������: �������������� ������ ������
MyList::MyList() : pHead(nullptr), pTail(nullptr), nodeCount(0) {}

// ���������� �������� � ����� ������
void appendToList(MyList& list, char c) {
    Node* newNode = new Node;          // ������� ����� ����
    newNode->payload.data = c;         // ���������� ������
    newNode->pNext = nullptr;          // ����� ���� ���������� ���������

    if (list.pTail) {                  // ���� ������ �� ����
        list.pTail->pNext = newNode;   // ����������� ����� ���� � �����
    }
    else {                           // ���� ������ ����
        list.pHead = newNode;          // ����� ���� ���������� ������
    }
    list.pTail = newNode;              // ��������� ��������� �� �����
    list.nodeCount++;                   // ����������� ������� �����
}

// ������ ������
void printList(const MyList& list) {
    Node* current = list.pHead;        // �������� � ������� ����
    while (current != nullptr) {       // ���� �� ��������� �����
        std::cout << current->payload.data << " ";
        current = current->pNext;      // ������� � ���������� ����
    }
    std::cout << std::endl;
}

// �������� ������� �������� � ������ (�������������� � �������������� ���-�������)
bool isElementInList(const MyList& list, char c) {
    bool exists[256] = { false };        // ���-������� ��� ASCII ��������
    Node* current = list.pHead;
    while (current != nullptr) {
        exists[static_cast<unsigned char>(current->payload.data)] = true;
        current = current->pNext;
    }
    return exists[static_cast<unsigned char>(c)];
}

// �������� ����������� ������
MyList createUniqueList(const MyList& list1, const MyList& list2) {
    MyList uniqueList;
    bool inList2[256] = { false };       // ���-������� ��� ��������� list2
    bool inUnique[256] = { false };      // ���-������� ��� ���������� ���������

    // ��������� inList2
    Node* current = list2.pHead;
    while (current != nullptr) {
        inList2[static_cast<unsigned char>(current->payload.data)] = true;
        current = current->pNext;
    }

    // ��������� �������� list1
    current = list1.pHead;
    while (current != nullptr) {
        char c = current->payload.data;
        if (!inList2[static_cast<unsigned char>(c)] && !inUnique[static_cast<unsigned char>(c)]) {
            appendToList(uniqueList, c);
            inUnique[static_cast<unsigned char>(c)] = true; // �������� ��� �����������
        }
        current = current->pNext;
    }
    return uniqueList;
}

// ������������ ������
void freeList(MyList& list) {
    Node* current = list.pHead;
    while (current != nullptr) {
        Node* next = current->pNext;
        delete current;                // ������� ������� ����
        current = next;
    }
    list.pHead = list.pTail = nullptr; // ���������� ���������
    list.nodeCount = 0;                // �������� �������
}