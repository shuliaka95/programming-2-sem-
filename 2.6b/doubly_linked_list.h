#pragma once

// Структура узла двусвязного списка
struct Node {
    double data;     // Значение, хранящееся в узле
    Node* prev;      // Указатель на предыдущий узел в списке
    Node* next;      // Указатель на следующий узел в списке

    // Конструктор узла: инициализирует данные и указатели
    Node(double val) : data(val), prev(nullptr), next(nullptr) {}
};

// Класс для управления двусвязным списком
class DoublyLinkedList {
private:
    Node* head;      // Указатель на первый узел списка
    Node* tail;      // Указатель на последний узел списка
    int size;        // Количество элементов в списке

public:
    DoublyLinkedList();          // Конструктор: создает пустой список
    ~DoublyLinkedList();         // Деструктор: освобождает память
    void push_back(double val);   // Добавляет элемент в конец списка
    Node* getNode(int index);     // Возвращает узел по индексу
    double calculateSum();        // Вычисляет сумму по условию задачи
};

