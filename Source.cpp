#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"

using namespace std;

// Функция для проверки колличества введенных аргументов командной строки. Пользователь должен передать два аргумента,
// если он передаст их меньще, то функция попросит их ввести.
void chek_cnt_arg(int cnt_arg, const char* argv[], char name_in[], char name_out[]) {
    // Для удобства дальнейшей работы копируем аргументы командной строки в переменные типа char*.
    if (cnt_arg == 1) {
        cout << "Не введены файлы для чтения и записи\nВведите файл для чтения: ";
        cin >> name_in;
        cout << "Введите файл для записи: ";
        cin >> name_out;
    }
    else if (cnt_arg == 2) {
        strcpy(name_in, argv[1]);
        cout << "Не введен файл для записи\nВведите файл для записи: ";
        cin >> name_out;
    }
    else {
        strcpy(name_in, argv[1]);
        strcpy(name_out, argv[2]);
    }
}


int main(int argc, const char* argv[]) {
    unsigned char symbol;
    // Переменные для хранения имен файлов для чтения и записи.
    char name_in[1000] = { '\0' }, name_out[1000] = { '\0' };
    chek_cnt_arg(argc, argv, name_in, name_out);
    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    chek_file(&fout, name_out, "w");
    file_encrypt(fin, fout);
    // Дальше нужно проверить шифровку. Надо открыть файл для записи на чтение и проверить каждый символ.
    fclose(fout);
    fout = fopen(name_out, "r");
    bool res = correct_file_encryption(fin, fout);
    if (res)
        cout << "Файл успешно зашифрован.\n";
    else
        cout << "Во время шифровки произошла ошибка. Дешифрованный файл не совпадает с исходным.\n";
    // Закрываем файлы.
    fclose(fin);
    fclose(fout);
    return 0;
}
