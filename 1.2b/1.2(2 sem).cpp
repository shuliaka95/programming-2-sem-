#include <iostream>
#include <cstring>
#include <cctype>
#include "func.h"

int main() {
    const int max_text_length = 1000;
    const int max_word_count = 100;
    const int max_word_length = 50;
    const int max_result_length = max_text_length;

    char text[max_text_length];
    char* words[max_word_count];
    char result[max_result_length];
    int word_count = 0;

    // Выделение памяти для слов
    for (int i = 0; i < max_word_count; ++i) {
        words[i] = new char[max_word_length];
    }

    // Ввод текста
    input_text(text, max_text_length);

    // Обработка текста
    create_word_array(text, words, word_count, max_word_length);
    sort_words(words, word_count);
    get_result_string(words, word_count, result, max_result_length);

    // Вывод результата
    std::cout << "\nSorted text: " << result << std::endl;

    // Освобождение памяти
    for (int i = 0; i < max_word_count; ++i) {
        delete[] words[i];
    }

    return 0;
}
