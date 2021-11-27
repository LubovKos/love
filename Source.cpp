#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"

using namespace std;

// ������� ��� �������� ����������� ��������� ���������� ��������� ������. ������������ ������ �������� ��� ���������,
// ���� �� �������� �� ������, �� ������� �������� �� ������.
void chek_cnt_arg(int cnt_arg, const char* argv[], char name_in[], char name_out[]) {
    // ��� �������� ���������� ������ �������� ��������� ��������� ������ � ���������� ���� char*.
    if (cnt_arg == 1) {
        cout << "�� ������� ����� ��� ������ � ������\n������� ���� ��� ������: ";
        cin >> name_in;
        cout << "������� ���� ��� ������: ";
        cin >> name_out;
    }
    else if (cnt_arg == 2) {
        strcpy(name_in, argv[1]);
        cout << "�� ������ ���� ��� ������\n������� ���� ��� ������: ";
        cin >> name_out;
    }
    else {
        strcpy(name_in, argv[1]);
        strcpy(name_out, argv[2]);
    }
}

// ������� ��������� ������������ ���������� � ��������� ������ ��� ������ ��� ������ � ����������� �� param_open.
void chek_file(FILE** file, char filename[], const char param_fopen[])
{
    while (strstr(filename, ".txt") == NULL or (*file = fopen(filename, param_fopen)) == NULL) {
        if (strcmp(param_fopen, "r") == 0)
            cout << "������ ����� ��� ������ ���, ��������� ����: ";
        else
            cout << "������ ����� ��� ������ ���, ��������� ����: ";
        cin >> filename;
    }
}

int main(int argc, const char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    unsigned char symbol;
    // ���������� ��� �������� ���� ������ ��� ������ � ������.
    char name_in[1000] = { '\0' }, name_out[1000] = { '\0' };
    chek_cnt_arg(argc, argv, name_in, name_out);
    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    chek_file(&fout, name_out, "w");
    file_encrypt(fin, fout);
    // ������ ����� ��������� ��������. ���� ������� ���� ��� ������ �� ������ � ��������� ������ ������.
    fclose(fout);
    fout = fopen(name_out, "r");
    bool res = correct_file_encryption(fin, fout);
    if (res)
        cout << "���� ������� ����������.\n";
    else
        cout << "�� ����� �������� ��������� ������. ������������� ���� �� ��������� � ��������.\n";
    // ��������� �����.
    fclose(fin);
    fclose(fout);
    return 0;
}
