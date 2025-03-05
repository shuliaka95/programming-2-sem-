#include "mylist.h"
#include <iostream>

// Конструктор списка: инициализирует пустой список
MyList::MyList() : pHead(nullptr), pTail(nullptr), nodeCount(0) {}

// Добавление элемента в конец списка
void appendToList(MyList& list, char c) {
    Node* newNode = new Node;          // Создаем новый узел
    newNode->payload.data = c;         // Записываем данные
    newNode->pNext = nullptr;          // Новый узел становится последним

    if (list.pTail) {                  // Если список не пуст
        list.pTail->pNext = newNode;   // Привязываем новый узел к концу
    }
    else {                           // Если список пуст
        list.pHead = newNode;          // Новый узел становится первым
    }
    list.pTail = newNode;              // Обновляем указатель на конец
    list.nodeCount++;                   // Увеличиваем счетчик узлов
}

// Печать списка
void printList(const MyList& list) {
    Node* current = list.pHead;        // Начинаем с первого узла
    while (current != nullptr) {       // Пока не достигнем конца
        std::cout << current->payload.data << " ";
        current = current->pNext;      // Переход к следующему узлу
    }
    std::cout << std::endl;
}

// Проверка наличия элемента в списке (оптимизировано с использованием хэш-таблицы)
bool isElementInList(const MyList& list, char c) {
    bool exists[256] = { false };        // Хэш-таблица для ASCII символов
    Node* current = list.pHead;
    while (current != nullptr) {
        exists[static_cast<unsigned char>(current->payload.data)] = true;
        current = current->pNext;
    }
    return exists[static_cast<unsigned char>(c)];
}

// Создание уникального списка
MyList createUniqueList(const MyList& list1, const MyList& list2) {
    MyList uniqueList;
    bool inList2[256] = { false };       // Хэш-таблица для элементов list2
    bool inUnique[256] = { false };      // Хэш-таблица для уникальных элементов

    // Заполняем inList2
    Node* current = list2.pHead;
    while (current != nullptr) {
        inList2[static_cast<unsigned char>(current->payload.data)] = true;
        current = current->pNext;
    }

    // Проверяем элементы list1
    current = list1.pHead;
    while (current != nullptr) {
        char c = current->payload.data;
        if (!inList2[static_cast<unsigned char>(c)] && !inUnique[static_cast<unsigned char>(c)]) {
            appendToList(uniqueList, c);
            inUnique[static_cast<unsigned char>(c)] = true; // Помечаем как добавленный
        }
        current = current->pNext;
    }
    return uniqueList;
}

// Освобождение памяти
void freeList(MyList& list) {
    Node* current = list.pHead;
    while (current != nullptr) {
        Node* next = current->pNext;
        delete current;                // Удаляем текущий узел
        current = next;
    }
    list.pHead = list.pTail = nullptr; // Сбрасываем указатели
    list.nodeCount = 0;                // Обнуляем счетчик
}