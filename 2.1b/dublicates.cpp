#include "dublicates.h"
#include <iostream>    // ��� �����/������
#include <algorithm>   // ��� ���������� (std::sort)
#include <random>      // ��� ��������� ��������� �����
#include <ctime>       // ��� ������������� ����������

// ��������� ����� ������ (������ ��� �������������� �����)
ProcessData process_input(InputMode mode) {
    // ������������� ���������: count_arr ����������� ������, result_size = 0
    ProcessData data{ new int[MAX_NUM + 1](), 0 };

    // ����� ������� �����
    if (mode == MANUAL) {
        std::cout << "Enter numbers (1-" << MAX_NUM << "). Ctrl+D/Z to end:\n";
        int x; // ���������� ��� �������� ���������� �����
        while (std::cin >> x) { // ������ ����� �� ����� �����
            if (x < 1 || x > MAX_NUM) continue; // ������� ������������ ��������
            if (data.count_arr[x] < 2) data.count_arr[x]++; // ����������� ������� (�������� �� 2)
        }
    }
    // ����� �������������� ���������
    else {
        int n; // ���������� ������������ �����
        std::cout << "Enter number of elements to generate: ";
        std::cin >> n;

        // ������������� ���������� ��������� �����
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<> distr(1, MAX_NUM);

        for (int i = 0; i < n; ++i) {
            int x = distr(gen); // ��������� �����
            if (data.count_arr[x] < 2) data.count_arr[x]++; // ���������� ��������
        }
    }

    // ������� ���������� �����, ������������� ����� ������
    for (int i = 1; i <= MAX_NUM; ++i) {
        if (data.count_arr[i] == 2) data.result_size++;
    }

    return data;
}

// �������� ���������������� ������� �����, ������������� ������
int* create_result(int* count, int size) {
    if (size == 0) return nullptr; // ���� ��� ���������� �����, ���������� nullptr

    int* result = new int[size]; // ��������� ������ ��� ���������
    int idx = 0; // ������ ��� ���������� �������

    // ���������� ������� �������, ������� ����������� ������
    for (int i = 1; i <= MAX_NUM; ++i) {
        if (count[i] == 2) result[idx++] = i;
    }

    std::sort(result, result + size); // ���������� �� �����������
    return result;
}

// ����� ���� ������ ������ �����
void print_menu() {
    std::cout << "Choose input method:\n"
        << "1 - Manual input\n"
        << "2 - Auto generation\n"
        << "Your choice: ";
}