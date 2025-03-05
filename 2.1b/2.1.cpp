#include "dublicates.h"
#include <iostream> // Для ввода/вывода

int main() {
    print_menu(); // Вывод меню
    int choice;   // Переменная для выбора режима
    std::cin >> choice;

    // Проверка корректности выбора
    if (choice != MANUAL && choice != AUTO) {
        std::cout << "Invalid choice!\n";
        return 1; // Завершение программы с ошибкой
    }

    // Обработка данных в зависимости от выбранного режима
    ProcessData data = process_input(static_cast<InputMode>(choice));

    // Создание и вывод результата
    int* result = create_result(data.count_arr, data.result_size);
    std::cout << "Result (" << data.result_size << " elements):\n";
    for (int i = 0; i < data.result_size; ++i) {
        std::cout << result[i] << ' '; // Построчный вывод элементов
    }
    std::cout << '\n';

    // Освобождение выделенной памяти
    delete[] data.count_arr; // Удаление массива счетчиков
    delete[] result;         // Удаление результата

    return 0;
}