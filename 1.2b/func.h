#pragma once
void input_text(char* buffer, int buffer_size);
void create_word_array(char* text, char** words, int& word_count, int max_word_length);
bool compare_words(const char* a, const char* b);
void sort_words(char** words, int word_count);
void get_result_string(char** words, int word_count, char* result, int max_result_length);