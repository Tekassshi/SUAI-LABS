// Для обнаружения утечек памяти

#define CRTDBG_MAP_ALLOC  
#include <cstdlib>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define NEW_DBG_NEW
#endif
#endif

// Основной код

#include <iostream>
#include "functions.h"

int main() {

	// переменные указатели для функции exceptions
	bool f1 = 0;
	bool f2 = 0;
	bool* fpointer1 = &f1;
	bool* fpointer2 = &f2;

	setlocale(LC_ALL, "rus");

	int i, j, k = 0, plus, mid, ost, spaces = 0, words, size, expsize;

	std::cout << "Введите длину строки: ";
	std::cin >> size;
	std::cout << std::endl;

	size += 1; // Дополнительное пространство для нуль-терминатора

	// Ссылка на массив слов
	char* str = new char[size];

	std::cout << "Введите строку: ";
	std::cin.get(); // Добавляем, чтобы сработал метод getline (из за остаточного \n)

	std::cin.getline(str, size);
	std::cout << std::endl;

	std::cout << "Введите необходимую длину строки: ";
	std::cin >> expsize;

	if (expsize < 0) {
		std::cout << "Длина строки не может быть отрицательной!\n";
		return 0;
	}

	expsize += 1; // Дополнительное пространство для нуль-терминатора

	// Ссылка на конечный массив
	char* outstring = new char[expsize];

	exccehck(fpointer1, fpointer2, str, outstring, size, expsize);

	// Если введённые данные не прошли проверку, то завершаем программу
	if (*fpointer1 == 1 || *fpointer2 == 1)
		return 0;

	count(str, size, &spaces, &words);

	std::cout << std::endl;

	transform(str, outstring, size, expsize, spaces);

	std::cout << std::endl;
	std::cout << "'" << outstring << "'";
	std::cout << std::endl;
	std::cout << "Длина строки: ";
	std::cout << strlen(outstring);
	std::cout << std::endl;

	delete[] str;
	delete[] outstring;

	// Для обнаружения утечек памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
}