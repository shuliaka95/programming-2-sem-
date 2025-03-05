#include "mylist.h"
#include <iostream>
#include <clocale> // Для setlocale

int main() {
    setlocale(LC_ALL, "Rus"); // Поддержка кириллицы

    MyList list1, list2;       // Создаем два списка

    // Заполнение list1
    int n1;
    std::cout << "Введите количество элементов в списке list1: ";
    std::cin >> n1;
    std::cout << "Введите элементы: ";
    for (int i = 0; i < n1; ++i) {
        char c;
        std::cin >> c;
        appendToList(list1, c);
    }

    // Заполнение list2
    int n2;
    std::cout << "Введите количество элементов в списке list2: ";
    std::cin >> n2;
    std::cout << "Введите элементы: ";
    for (int i = 0; i < n2; ++i) {
        char c;
        std::cin >> c;
        appendToList(list2, c);
    }

    // Создание и вывод уникального списка
    MyList uniqueList = createUniqueList(list1, list2);
    std::cout << "list1: ";
    printList(list1);
    std::cout << "list2: ";
    printList(list2);
    std::cout << "uniqueList: ";
    printList(uniqueList);

    // Освобождение памяти
    freeList(list1);
    freeList(list2);
    freeList(uniqueList);

    return 0;
}