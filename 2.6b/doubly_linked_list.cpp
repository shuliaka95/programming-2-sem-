#include "doubly_linked_list.h"

// ������������� ������: ��������� ��������� ��������
void initList(DoublyLinkedList* list) {
    list->head = nullptr; // ������ ����, ������� ��������� ��������
    list->tail = nullptr;
    list->size = 0;       // ������ ����� 0
}

// ������� ������ ������
void freeList(DoublyLinkedList* list) {
    Node* current = list->head; // �������� � ������� ����

    // �������� �� ���� ����� � ������� ��
    while (current != nullptr) {
        Node* next = current->next; // ��������� ������ �� ��������� ����
        delete current;             // ������� ������� ����
        current = next;             // ��������� � ����������
    }

    // ���������� ��������� ������
    initList(list);
}

// ���������� �������� � ����� ������
void pushBack(DoublyLinkedList* list, double val) {
    // ������� ����� ����
    Node* newNode = new Node{ val, nullptr, nullptr };

    if (list->tail == nullptr) {
        // ���� ������ ����, ����� ���� ���������� ������������
        list->head = list->tail = newNode;
    }
    else {
        // ����������� ����� ���� � ����� ������
        list->tail->next = newNode; // ������ ����� -> ����� ����
        newNode->prev = list->tail;  // ����� ���� <- ������ �����
        list->tail = newNode;        // ��������� ����� ������
    }
    list->size++; // ����������� ������� ���������
}

// ��������� ���� �� �������
Node* getNode(const DoublyLinkedList* list, int index) {
    // �������� ������������ �������
    if (index < 0 || index >= list->size) return nullptr;

    Node* current = list->head; // �������� � ������ ������

    // ������������ ������ �� 'index' �����
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current; // ���������� ��������� ����
}

// ���������� ����� ������������ ��� ���������
double calculateSum(const DoublyLinkedList* list) {
    // �������� �������� ���������� ���������
    if (list->size % 2 != 0) {
        std::cerr << "Error: Number of elements must be even!\n";
        return 0.0;
    }

    const int n = list->size / 2; // ���������� ���
    double sum = 0.0;

    // ��������� �� �������� a_n (������ n-1) � a_{n+1} (������ n)
    Node* left = getNode(list, n - 1);
    Node* right = getNode(list, n);

    // ��������� ������������ ���, �������� �� ������ � �����
    for (int i = 0; i < n; ++i) {
        sum += left->data * right->data; // ��������� ������������
        left = left->prev;  // �������� ����� ��������� � ������
        right = right->next; // �������� ������ ��������� � �����
    }

    return sum;
}