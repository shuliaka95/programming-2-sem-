#include "func.h"
#include <iostream>
#include <cstring>
#include <cctype>


// Функция для ввода текста с клавиатуры
void input_text(char* buffer, int buffer_size) {
    std::cout << "Enter text: ";
    std::cin.getline(buffer, buffer_size);

    // Очистка буфера в случае переполнения
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Функция для создания массива слов
void create_word_array(char* text, char** words, int& word_count, int max_word_length) {
    const char* delimiters = " .,:;!?()-";
    char* next_token = nullptr;
    char* word = strtok_s(text, delimiters, &next_token);
    word_count = 0;

    while (word && word_count < max_word_length) {
        strcpy_s(words[word_count], max_word_length, word);
        word_count++;
        word = strtok_s(nullptr, delimiters, &next_token);
    }
}

// Функция сравнения слов
bool compare_words(const char* a, const char* b) {
    return std::tolower(static_cast<unsigned char>(a[0])) <
        std::tolower(static_cast<unsigned char>(b[0]));
}

// Сортировка слов пузырьком
void sort_words(char** words, int word_count) {
    for (int i = 0; i < word_count - 1; ++i) {
        for (int j = 0; j < word_count - i - 1; ++j) {
            if (compare_words(words[j + 1], words[j])) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

// Формирование результирующей строки
void get_result_string(char** words, int word_count, char* result, int max_result_length) {
    result[0] = '\0';
    for (int i = 0; i < word_count; ++i) {
        strcat_s(result, max_result_length, words[i]);
        if (i < word_count - 1) {
            strcat_s(result, max_result_length, " ");
        }
    }
}