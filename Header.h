#ifndef CRYPT_HPP
#define CRYPT_HPP

// Функция кодирует буквы кирилицы в соответствии с переданными ключами для заглывных и строчных букв.
wchar_t encrypt_symbol(char symbol);

// Функция шифрует переданный файл data и записывает результат в файл fout.
void file_encrypt(FILE* data, FILE* fout);

// Функция дешифрует букву кирилицы.
wchar_t decrypt_symbol(char symbol);

// Функция дешифрует зашифрованный файл и проверяет на совпадение с исходным.
bool correct_file_encryption(FILE* data, FILE* crypt_data);

#endif // CRYPT_HPP