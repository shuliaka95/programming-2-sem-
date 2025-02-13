#include <iostream>
#include "func.h"

// ������� ��� ����� ������� � ��� �������
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

// ������� ��� ������ ������������� ����������� ��������
int* find_max_unique(int* arr, int size) {
    if (size == 0) return 0;  // ���������� 0, ���� ������ ����

    int* max_ptr = arr;  // ��������� �� ������������ �������
    int max_value = *arr;  // �������� ������������� ��������
    int count = 1;  // ���������� ��������� ������������� ��������

    // ������� ������������ ������� � ������� ��� ���������
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

    // ���� ������������ ������� ����������� ����� ���� ���, �������� ��� �� ����
    if (count == 1) {
        *max_ptr = 0;
        return max_ptr;
    }

    // ���� ������������ ������� ����������� ����� ������ ����, �������� ������ ��������� �� ����
    for (int i = 0; i < size; ++i) {
        if (arr[i] == max_value) {
            arr[i] = 0;
            return &arr[i];
        }
    }

    return 0;  // �� ������, ���� ������ ����
}