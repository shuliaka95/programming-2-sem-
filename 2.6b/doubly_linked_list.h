#pragma once

#include <iostream>

// Структура узла двусвязного списка
struct Node {
    double data;     // Значение, хранящееся в узле
    Node* prev;      // Указатель на предыдущий узел
    Node* next;      // Указатель на следующий узел
};

// Структура для управления двусвязным списком
struct DoublyLinkedList {
    Node* head = nullptr; // Указатель на первый элемент списка
    Node* tail = nullptr; // Указатель на последний элемент списка
    int size = 0;         // Текущее количество элементов в списке
};

// Инициализирует список, устанавливая начальные значения
void initList(DoublyLinkedList* list);

// Освобождает всю память, занятую списком
void freeList(DoublyLinkedList* list);

// Добавляет новый элемент в конец списка
void pushBack(DoublyLinkedList* list, double val);

// Возвращает узел по указанному индексу (начиная с 0)
Node* getNode(const DoublyLinkedList* list, int index);

// Вычисляет сумму произведений пар элементов: a1*an+1 + a2*an+2 + ... + an*a2n
double calculateSum(const DoublyLinkedList* list);