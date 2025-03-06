#include "doubly_linked_list.h"

// Инициализация списка: установка начальных значений
void initList(DoublyLinkedList* list) {
    list->head = nullptr; // Список пуст, поэтому указатели обнулены
    list->tail = nullptr;
    list->size = 0;       // Размер равен 0
}

// Очистка памяти списка
void freeList(DoublyLinkedList* list) {
    Node* current = list->head; // Начинаем с первого узла

    // Проходим по всем узлам и удаляем их
    while (current != nullptr) {
        Node* next = current->next; // Сохраняем ссылку на следующий узел
        delete current;             // Удаляем текущий узел
        current = next;             // Переходим к следующему
    }

    // Сбрасываем параметры списка
    initList(list);
}

// Добавление элемента в конец списка
void pushBack(DoublyLinkedList* list, double val) {
    // Создаем новый узел
    Node* newNode = new Node{ val, nullptr, nullptr };

    if (list->tail == nullptr) {
        // Если список пуст, новый узел становится единственным
        list->head = list->tail = newNode;
    }
    else {
        // Привязываем новый узел к концу списка
        list->tail->next = newNode; // Старый хвост -> новый узел
        newNode->prev = list->tail;  // Новый узел <- старый хвост
        list->tail = newNode;        // Обновляем хвост списка
    }
    list->size++; // Увеличиваем счетчик элементов
}

// Получение узла по индексу
Node* getNode(const DoublyLinkedList* list, int index) {
    // Проверка корректности индекса
    if (index < 0 || index >= list->size) return nullptr;

    Node* current = list->head; // Начинаем с головы списка

    // Перемещаемся вперед на 'index' шагов
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current; // Возвращаем найденный узел
}

// Вычисление суммы произведений пар элементов
double calculateSum(const DoublyLinkedList* list) {
    // Проверка четности количества элементов
    if (list->size % 2 != 0) {
        std::cerr << "Error: Number of elements must be even!\n";
        return 0.0;
    }

    const int n = list->size / 2; // Количество пар
    double sum = 0.0;

    // Указатели на элементы a_n (индекс n-1) и a_{n+1} (индекс n)
    Node* left = getNode(list, n - 1);
    Node* right = getNode(list, n);

    // Суммируем произведения пар, двигаясь от центра к краям
    for (int i = 0; i < n; ++i) {
        sum += left->data * right->data; // Добавляем произведение
        left = left->prev;  // Сдвигаем левый указатель к началу
        right = right->next; // Сдвигаем правый указатель к концу
    }

    return sum;
}