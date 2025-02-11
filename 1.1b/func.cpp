#include "func.h"
#include <iostream>

void print_matrix(int* matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << *(matrix + i * size + j) << "\t";
        }
        std::cout << "\n";
    }
}

void fill_by_spiral(int* matrix, const int* values, int size) {
    int top = 0, bottom = size - 1, left = 0, right = size - 1;
    int index_of_element = 0;

    while (index_of_element < size * size) {
        for (int i = right; i >= left; i--)
            *(matrix + top * size + i) = values[index_of_element++];
        top++; //move from right to left

        for (int i = top; i <= bottom; i++)
            *(matrix + i * size + left) = values[index_of_element++];
        left++; //move down

        if (top <= bottom) {
            for (int i = left; i <= right; i++)
                *(matrix + bottom * size + i) = values[index_of_element++];
            bottom--;
        } //move from left to right

        // move up
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                *(matrix + i * size + right) = values[index_of_element++];
            right--;
        }
    }
}

void enter_matrix(int* values, int size) {
    std::cout << "Enter " << size * size << " elements: ";
    for (int i = 0; i < size * size; i++) {
        std::cin >> values[i];
    }
}