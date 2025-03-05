#pragma once

// Структура для хранения данных в узле списка
struct MyPayload {
    char data; // Символ, хранящийся в узле
};

// Структура узла списка
struct Node {
    MyPayload payload; // Данные узла
    Node* pNext;       // Указатель на следующий узел
};

// Структура для управления списком
struct MyList {
    Node* pHead;    // Указатель на первый узел
    Node* pTail;    // Указатель на последний узел
    int nodeCount;  // Количество узлов в списке

    MyList();       // Конструктор для инициализации списка
};

// Прототипы функций
void appendToList(MyList& list, char c);
void printList(const MyList& list);
bool isElementInList(const MyList& list, char c);
MyList createUniqueList(const MyList& list1, const MyList& list2);
void freeList(MyList& list); // Освобождение памяти
