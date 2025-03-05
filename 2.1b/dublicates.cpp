#include "dublicates.h"
#include <iostream>    // Для ввода/вывода
#include <algorithm>   // Для сортировки (std::sort)
#include <random>      // Для генерации случайных чисел
#include <ctime>       // Для инициализации генератора

// Обработка ввода данных (ручной или автоматический режим)
ProcessData process_input(InputMode mode) {
    // Инициализация структуры: count_arr заполняется нулями, result_size = 0
    ProcessData data{ new int[MAX_NUM + 1](), 0 };

    // Режим ручного ввода
    if (mode == MANUAL) {
        std::cout << "Enter numbers (1-" << MAX_NUM << "). Ctrl+D/Z to end:\n";
        int x; // Переменная для хранения введенного числа
        while (std::cin >> x) { // Чтение чисел до конца ввода
            if (x < 1 || x > MAX_NUM) continue; // Пропуск некорректных значений
            if (data.count_arr[x] < 2) data.count_arr[x]++; // Увеличиваем счетчик (максимум до 2)
        }
    }
    // Режим автоматической генерации
    else {
        int n; // Количество генерируемых чисел
        std::cout << "Enter number of elements to generate: ";
        std::cin >> n;

        // Инициализация генератора случайных чисел
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<> distr(1, MAX_NUM);

        for (int i = 0; i < n; ++i) {
            int x = distr(gen); // Генерация числа
            if (data.count_arr[x] < 2) data.count_arr[x]++; // Обновление счетчика
        }
    }

    // Подсчет количества чисел, встречающихся ровно дважды
    for (int i = 1; i <= MAX_NUM; ++i) {
        if (data.count_arr[i] == 2) data.result_size++;
    }

    return data;
}

// Создание отсортированного массива чисел, встречающихся дважды
int* create_result(int* count, int size) {
    if (size == 0) return nullptr; // Если нет подходящих чисел, возвращаем nullptr

    int* result = new int[size]; // Выделение памяти под результат
    int idx = 0; // Индекс для заполнения массива

    // Заполнение массива числами, которые встретились дважды
    for (int i = 1; i <= MAX_NUM; ++i) {
        if (count[i] == 2) result[idx++] = i;
    }

    std::sort(result, result + size); // Сортировка по возрастанию
    return result;
}

// Вывод меню выбора режима ввода
void print_menu() {
    std::cout << "Choose input method:\n"
        << "1 - Manual input\n"
        << "2 - Auto generation\n"
        << "Your choice: ";
}