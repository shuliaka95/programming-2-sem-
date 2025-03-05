#pragma once

// ��������� ���� ����������� ������
struct Node {
    double data;     // ��������, ���������� � ����
    Node* prev;      // ��������� �� ���������� ���� � ������
    Node* next;      // ��������� �� ��������� ���� � ������

    // ����������� ����: �������������� ������ � ���������
    Node(double val) : data(val), prev(nullptr), next(nullptr) {}
};

// ����� ��� ���������� ���������� �������
class DoublyLinkedList {
private:
    Node* head;      // ��������� �� ������ ���� ������
    Node* tail;      // ��������� �� ��������� ���� ������
    int size;        // ���������� ��������� � ������

public:
    DoublyLinkedList();          // �����������: ������� ������ ������
    ~DoublyLinkedList();         // ����������: ����������� ������
    void push_back(double val);   // ��������� ������� � ����� ������
    Node* getNode(int index);     // ���������� ���� �� �������
    double calculateSum();        // ��������� ����� �� ������� ������
};

