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

int main() {

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

	expsize += 1; // Дополнительное пространство для нуль-терминатора

	//Ссылка на конечный массив
	char* outstring = new char[expsize];

	if (strlen(str) != size-1) {
		std::cout << std::endl;
		std::cout << "Введённая строка не соответствует заданному размеру!";
		std::cout << std::endl;
		delete[] str;
		delete[] outstring;
		return 0;
	}
	else if (expsize == size) {
		std::cout << std::endl;
		std::cout << "В вашей строке уже достаточно символов!";
		std::cout << std::endl;
		delete[] str;
		delete[] outstring;
		return 0;
	}

	// Определеяем количество пробелов в слове
	for (i = 0; i < size; i++) {
		if (str[i] == ' ') {
			spaces += 1;
		}
	}

	words = spaces + 1;     // Количество слов

	std::cout << std::endl;

	plus = expsize - size;  // Количество пробелов, которые нужно добавить
	mid = plus / spaces;    // Среднее кол-во пробелов, которое необходимо добавить
	ost = plus % spaces;    // Остаточное кол-во пробелов, которые добавляем в конец

	// k - счётчик для нового массива
	for (i = 0; i < size; i++) {
		outstring[k] = str[i];
		k += 1;

		if (str[i] == ' ') {
			for (j = 0; j < mid; j++) {
				outstring[k] = ' ';
				k += 1;
			}
		}
	}

	// Заполняем остатки пробелов начиная с нуль-терминатора
	k -= 1;

	for (j = 0; j < ost; j++) {
		outstring[k] = ' ';
		std::cout << outstring[k];
		k += 1;
	}

	// Устанавливаем новый нуль-терминатор
	outstring[expsize-1] = '\0';

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