#ifndef CRYPT_HPP
#define CRYPT_HPP

// ������� �������� ����� �������� � ������������ � ����������� ������� ��� ��������� � �������� ����.
wchar_t encrypt_symbol(char symbol);

// ������� ������� ���������� ���� data � ���������� ��������� � ���� fout.
void file_encrypt(FILE* data, FILE* fout);

// ������� ��������� ����� ��������.
wchar_t decrypt_symbol(char symbol);

// ������� ��������� ������������� ���� � ��������� �� ���������� � ��������.
bool correct_file_encryption(FILE* data, FILE* crypt_data);

#endif // CRYPT_HPP