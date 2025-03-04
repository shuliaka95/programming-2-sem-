#include "dublicates.h"
#include <iostream>

int main() {
    print_menu();
    int choice;
    std::cin >> choice;

    if (choice != MANUAL && choice != AUTO) {
        std::cout << "Invalid choice!\n";
        return 1;
    }

    ProcessData data = process_input(static_cast<InputMode>(choice));

    std::cout << "\nOriginal array (" << data.source_size << " elements):\n";
    for (int i = 0; i < data.source_size; ++i)
        std::cout << data.source_arr[i] << ' ';
    std::cout << "\n\n";

    int* result = create_result(data.count_arr, data.result_size);
    std::cout << "Result (" << data.result_size << " elements):\n";
    for (int i = 0; i < data.result_size; ++i)
        std::cout << result[i] << ' ';
    std::cout << '\n';

    delete[] data.source_arr;
    delete[] data.count_arr;
    delete[] result;
    return 0;
}