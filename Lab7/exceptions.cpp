/*
	Функция ищет исключения, которые могут возникнуть при вводе данных для строки,
	в числе передаваемых параметров есть указатели, значение которых мы меняем внутри функции,
	и при значении "1" в функции main(), программа завершает работу.
*/

#include <iostream>

void exceptions(bool* fpointer1, bool* fpointer2, char* str, char* outstring, int size, int expsize) {
	if (strlen(str) != (size - 1)) {
		std::cout << std::endl;
		std::cout << "Введённая строка не соответствует заданному размеру!";
		std::cout << std::endl;
		delete[] str;
		delete[] outstring;
		*fpointer1 = 1;
	}
	else if (expsize <= size) {
		std::cout << std::endl;
		std::cout << "В вашей строке уже достаточно символов!";
		std::cout << std::endl;
		delete[] str;
		delete[] outstring;
		*fpointer2 = 1;
	}
}