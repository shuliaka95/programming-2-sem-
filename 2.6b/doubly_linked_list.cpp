#include "doubly_linked_list.h"
#include <iostream>

// Конструктор: инициализирует пустой список
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Деструктор: удаляет все узлы списка
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;         // Начинаем с первого узла
    while (current != nullptr) {  // Пока не дойдем до конца
        Node* next = current->next; // Сохраняем ссылку на следующий узел
        delete current;           // Удаляем текущий узел
        current = next;           // Переходим к следующему узлу
    }
}

// Добавляет элемент в конец списка
void DoublyLinkedList::push_back(double val) {
    Node* newNode = new Node(val); // Создаем новый узел
    if (!tail) {                   // Если список пуст
        head = tail = newNode;     // Новый узел становится и головой, и хвостом
    }
    else {
        tail->next = newNode;      // Привязываем новый узел к концу списка
        newNode->prev = tail;      // Устанавливаем обратную связь
        tail = newNode;            // Обновляем хвост списка
    }
    size++;                        // Увеличиваем счетчик элементов
}

// Возвращает узел по указанному индексу (индексация с 0)
Node* DoublyLinkedList::getNode(int index) {
    if (index < 0 || index >= size) { // Проверка на корректность индекса
        return nullptr;
    }
    Node* current = head;          // Начинаем с первого узла
    for (int i = 0; i < index; ++i) { // Перемещаемся на index шагов вперед
        current = current->next;
    }
    return current;                // Возвращаем найденный узел
}

// Вычисляет сумму произведений пар элементов по условию задачи
double DoublyLinkedList::calculateSum() {
    if (size % 2 != 0) {           // Проверка: количество элементов должно быть четным
        std::cerr << "Error: Number of elements must be even!\n";
        return 0.0;
    }

    double sum = 0.0;              // Инициализация суммы
    int n = size / 2;              // Вычисляем половину размера списка

    // Начальные узлы: left = a_n, right = a_{n+1}
    Node* left = getNode(n - 1);   // Узел с индексом n-1 (a_n)
    Node* right = getNode(n);      // Узел с индексом n (a_{n+1})

    // Суммируем произведения пар элементов
    for (int i = 0; i < n; ++i) {
        sum += left->data * right->data; // Добавляем произведение текущих узлов
        left = left->prev;         // Двигаемся к началу списка
        right = right->next;       // Двигаемся к концу списка
    }

    return sum;                    // Возвращаем итоговую сумму
}