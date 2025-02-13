#include <iostream>
#include "func.h"

int main() {
    const int MAX_SIZE = 100;  // Максимальный размер статического массива
    int arr[MAX_SIZE];  // Статический массив
    int size = 0;  // Размер массива

    // Ввод массива
    input_array(arr, size);

    if (size <= 0) {
        std::cout << "Array is empty or invalid size provided." << std::endl;
        return 0;
    }

    // Поиск максимального уникального элемента
    int* result = find_max_unique(arr, size);

    if (result) {
        std::cout << "The maximum unique number was found and replaced with zero: " << *result << std::endl;
    }
    else {
        std::cout << "No unique maximum number found. One of the maximum numbers was replaced with zero." << std::endl;
    }

    // Вывод измененного массива
    std::cout << "Modified array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}