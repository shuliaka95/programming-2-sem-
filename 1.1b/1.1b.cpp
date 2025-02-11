#include <iostream>
#include "func.h"

int main()
{
    int size = 0;
    std::cout << "Enter matrix order n: ";
    std::cin >> size;

    int* values{ new int[size * size] };
    int* matrix{ new int[size * size] };

    enter_matrix(values, size);

    fill_by_spiral(matrix, values, size);

    print_matrix(matrix, size);
}