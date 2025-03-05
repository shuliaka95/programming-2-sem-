#include "doubly_linked_list.h"
#include <iostream>

int main() {
    DoublyLinkedList list;         // Создаем экземпляр списка
    int n;                         // Количество элементов

    // Ввод количества элементов с проверкой
    std::cout << "Enter number of elements (must be even): ";
    std::cin >> n;
    if (n <= 0 || n % 2 != 0) {    // Если ввод некорректен
        std::cerr << "Invalid input! Number must be positive and even.\n";
        return 1;                  // Завершаем программу с ошибкой
    }

    // Заполнение списка
    std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        double val;
        std::cin >> val;           // Считываем значение
        list.push_back(val);       // Добавляем его в список
    }

    // Вычисление и вывод результата
    double result = list.calculateSum();
    std::cout << "Result: " << result << std::endl;

    return 0;                      // Успешное завершение программы
}