#pragma once

// ��������� ��� �������� ������ � ���� ������
struct MyPayload {
    char data; // ������, ���������� � ����
};

// ��������� ���� ������
struct Node {
    MyPayload payload; // ������ ����
    Node* pNext;       // ��������� �� ��������� ����
};

// ��������� ��� ���������� �������
struct MyList {
    Node* pHead;    // ��������� �� ������ ����
    Node* pTail;    // ��������� �� ��������� ����
    int nodeCount;  // ���������� ����� � ������

    MyList();       // ����������� ��� ������������� ������
};

// ��������� �������
void appendToList(MyList& list, char c);
void printList(const MyList& list);
bool isElementInList(const MyList& list, char c);
MyList createUniqueList(const MyList& list1, const MyList& list2);
void freeList(MyList& list); // ������������ ������
