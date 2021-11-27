#include <iostream>
#include <stdio.h>
#include "Header.h"

// Функция кодирует буквы.
wchar_t encrypt_symbol(char symbol){
	if (not iswalpha(symbol) or (towlower(symbol) == 'ё'))
		return symbol;
	int new_symbol = int(symbol) + 5;
	if ((new_symbol <= -1 && symbol >= -32) || (new_symbol <= -33 && symbol < -32))
		return char(int(symbol) + 5);
	else
		return char(int(symbol) - 27);

}

// Функция шифрует переданный файл data и записывает результат в файл fout.
void file_encrypt(FILE* data, FILE* fout){
	char cur_char, cur_char1;
	while (true){
		cur_char = getwc(data);
		if (feof(data))
			return;
		cur_char1 = encrypt_symbol(cur_char);
		putwc(cur_char1, fout);
	}
	return;
}

// Функция дешифрует букву кирилицы.
char decrypt_symbol(char symbol){
	if (not iswalpha(symbol) or (towlower(symbol) == 'ё'))
		return symbol;
	int new_symbol = int(symbol) - 5;
	if ((new_symbol >= -32 && symbol >= -32) || (new_symbol >= -64 && symbol < -32))
		return char(int(symbol) - 5);
	else
		return char(int(symbol) + 27);
}

// Функция дешифрует зашифрованный файл и проверяет на совпадение с исходным.
bool correct_file_encryption(FILE* data, FILE* crypt_data){
	char ch_text, ch_crtext, res;
	while (true){
		ch_text = getwc(data);
		ch_crtext = getwc(crypt_data);
		if (feof(data))
			return true;
		res = decrypt_symbol(ch_crtext);
		if (ch_text != res)
			return false;
	}
	return flag;
}

