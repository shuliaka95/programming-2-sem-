#pragma once

#include <iostream>

// ��������� ���� ����������� ������
struct Node {
    double data;     // ��������, ���������� � ����
    Node* prev;      // ��������� �� ���������� ����
    Node* next;      // ��������� �� ��������� ����
};

// ��������� ��� ���������� ���������� �������
struct DoublyLinkedList {
    Node* head = nullptr; // ��������� �� ������ ������� ������
    Node* tail = nullptr; // ��������� �� ��������� ������� ������
    int size = 0;         // ������� ���������� ��������� � ������
};

// �������������� ������, ������������ ��������� ��������
void initList(DoublyLinkedList* list);

// ����������� ��� ������, ������� �������
void freeList(DoublyLinkedList* list);

// ��������� ����� ������� � ����� ������
void pushBack(DoublyLinkedList* list, double val);

// ���������� ���� �� ���������� ������� (������� � 0)
Node* getNode(const DoublyLinkedList* list, int index);

// ��������� ����� ������������ ��� ���������: a1*an+1 + a2*an+2 + ... + an*a2n
double calculateSum(const DoublyLinkedList* list);