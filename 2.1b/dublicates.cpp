#include "dublicates.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

ProcessData process_input(InputMode mode) {
    ProcessData data{ nullptr, 0, new int[MAX_NUM + 1](), 0 };
    int capacity = 0;

    if (mode == MANUAL) {
        std::cout << "Enter numbers (1-" << MAX_NUM << "). Ctrl+D/Z to end:\n";
        int x;
        while (std::cin >> x) {
            if (x < 1 || x > MAX_NUM) continue;

            if (data.source_size >= capacity) {
                capacity = capacity ? capacity * 2 : 1;
                int* new_arr = new int[capacity];
                std::copy(data.source_arr, data.source_arr + data.source_size, new_arr);
                delete[] data.source_arr;
                data.source_arr = new_arr;
            }

            data.source_arr[data.source_size++] = x;
            if (data.count_arr[x] < 2) data.count_arr[x]++;
        }
    }
    else {
        int n;
        std::cout << "Enter number of elements to generate: ";
        std::cin >> n;
        data.source_arr = new int[n];
        data.source_size = n;

        std::mt19937 gen(time(0));
        std::uniform_int_distribution<> distr(1, MAX_NUM);

        for (int i = 0; i < n; ++i) {
            int x = distr(gen);
            data.source_arr[i] = x;
            if (data.count_arr[x] < 2) data.count_arr[x]++;
        }
    }

    for (int i = 1; i <= MAX_NUM; ++i)
        if (data.count_arr[i] == 2) data.result_size++;

    return data;
}

int* create_result(int* count, int size) {
    int* result = new int[size];
    int idx = 0;
    for (int i = 1; i <= MAX_NUM; ++i)
        if (count[i] == 2) result[idx++] = i;

    std::sort(result, result + size);
    return result;
}

void print_menu() {
    std::cout << "Choose input method:\n"
        << "1 - Manual input\n"
        << "2 - Auto generation\n"
        << "Your choice: ";
}