#include <iostream>
#include "func.h"

// Функция для ввода массива и его размера
void input_array(int* arr, int& size) {
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Invalid size. Size must be a positive integer." << std::endl;
        return;
    }

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

// Функция для поиска максимального уникального элемента
int* find_max_unique(int* arr, int size) {
    if (size == 0) return 0;  // Возвращаем 0, если массив пуст

    int* max_ptr = arr;  // Указатель на максимальный элемент
    int max_value = *arr;  // Значение максимального элемента
    int count = 1;  // Количество вхождений максимального элемента

    // Находим максимальный элемент и считаем его вхождения
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max_value) {
            max_value = arr[i];
            max_ptr = &arr[i];
            count = 1;
        }
        else if (arr[i] == max_value) {
            ++count;
        }
    }

    // Если максимальный элемент встречается ровно один раз, заменяем его на ноль
    if (count == 1) {
        *max_ptr = 0;
        return max_ptr;
    }

    // Если максимальный элемент встречается более одного раза, заменяем первый найденный на ноль
    for (int i = 0; i < size; ++i) {
        if (arr[i] == max_value) {
            arr[i] = 0;
            return &arr[i];
        }
    }

    return 0;  // На случай, если массив пуст
}