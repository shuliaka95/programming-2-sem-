#pragma once
enum InputMode { MANUAL = 1, AUTO };

const int MAX_NUM = 10000000;

struct ProcessData {
    int* count_arr;      // ������ ��������� ��� ����� �� 1 �� MAX_NUM
    int result_size;    // ���������� �����, ������������� ����� ������
};

ProcessData process_input(InputMode mode);  // ��������� ����� ������
int* create_result(int* count, int size);   // �������� ���������������� ����������
void print_menu();  // ����� ���� ������ ������