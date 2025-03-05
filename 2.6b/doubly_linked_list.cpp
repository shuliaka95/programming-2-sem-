#include "doubly_linked_list.h"
#include <iostream>

// �����������: �������������� ������ ������
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// ����������: ������� ��� ���� ������
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;         // �������� � ������� ����
    while (current != nullptr) {  // ���� �� ������ �� �����
        Node* next = current->next; // ��������� ������ �� ��������� ����
        delete current;           // ������� ������� ����
        current = next;           // ��������� � ���������� ����
    }
}

// ��������� ������� � ����� ������
void DoublyLinkedList::push_back(double val) {
    Node* newNode = new Node(val); // ������� ����� ����
    if (!tail) {                   // ���� ������ ����
        head = tail = newNode;     // ����� ���� ���������� � �������, � �������
    }
    else {
        tail->next = newNode;      // ����������� ����� ���� � ����� ������
        newNode->prev = tail;      // ������������� �������� �����
        tail = newNode;            // ��������� ����� ������
    }
    size++;                        // ����������� ������� ���������
}

// ���������� ���� �� ���������� ������� (���������� � 0)
Node* DoublyLinkedList::getNode(int index) {
    if (index < 0 || index >= size) { // �������� �� ������������ �������
        return nullptr;
    }
    Node* current = head;          // �������� � ������� ����
    for (int i = 0; i < index; ++i) { // ������������ �� index ����� ������
        current = current->next;
    }
    return current;                // ���������� ��������� ����
}

// ��������� ����� ������������ ��� ��������� �� ������� ������
double DoublyLinkedList::calculateSum() {
    if (size % 2 != 0) {           // ��������: ���������� ��������� ������ ���� ������
        std::cerr << "Error: Number of elements must be even!\n";
        return 0.0;
    }

    double sum = 0.0;              // ������������� �����
    int n = size / 2;              // ��������� �������� ������� ������

    // ��������� ����: left = a_n, right = a_{n+1}
    Node* left = getNode(n - 1);   // ���� � �������� n-1 (a_n)
    Node* right = getNode(n);      // ���� � �������� n (a_{n+1})

    // ��������� ������������ ��� ���������
    for (int i = 0; i < n; ++i) {
        sum += left->data * right->data; // ��������� ������������ ������� �����
        left = left->prev;         // ��������� � ������ ������
        right = right->next;       // ��������� � ����� ������
    }

    return sum;                    // ���������� �������� �����
}