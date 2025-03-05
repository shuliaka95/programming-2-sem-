#pragma once
enum InputMode { MANUAL = 1, AUTO };

const int MAX_NUM = 10000000;

struct ProcessData {
    int* count_arr;      // Массив счетчиков для чисел от 1 до MAX_NUM
    int result_size;    // Количество чисел, встречающихся ровно дважды
};

ProcessData process_input(InputMode mode);  // Обработка ввода данных
int* create_result(int* count, int size);   // Создание отсортированного результата
void print_menu();  // Вывод меню выбора режима