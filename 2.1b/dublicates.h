#pragma once
enum InputMode { MANUAL = 1, AUTO };

const int MAX_NUM = 10000000;

struct ProcessData {
    int* source_arr;
    int source_size;
    int* count_arr;
    int result_size;
};

ProcessData process_input(InputMode mode);
int* create_result(int* count, int size);
void print_menu();
