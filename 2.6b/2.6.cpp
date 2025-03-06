#include "doubly_linked_list.h"

int main() {
    DoublyLinkedList list;
    initList(&list); // Инициализация списка

    // Ввод количества элементов
    int n;
    std::cout << "Enter number of elements (must be whole number): ";
    std::cin >> n;

    // Проверка корректности ввода
    if (n <= 0 || n % 2 != 0) {
        std::cout << "Invalid input! Number must be positive and whole number.\n";
        freeList(&list); // Очистка памяти даже при ошибке ввода
        return 1;
    }

    // Заполнение списка значениями
    std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        double val;
        std::cin >> val;
        pushBack(&list, val); // Добавление элемента
    }

    // Вычисление и вывод результата
    std::cout << "Result: " << calculateSum(&list) << "\n";

    freeList(&list); // Освобождение памяти
    return 0;
}