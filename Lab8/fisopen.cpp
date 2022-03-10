// Функция для проверки существования и открытия файла

#include <fstream>
#include <iostream>

// Передача файлов по указателю, тк сам файл это объект

bool fisopen(std::ifstream* in, std::ofstream* out) {
	bool f = 1;

	if (!(*in).is_open()) {
		std::cout << "Файл для чтения не найден!" << std::endl;
		f = 0;
	}
	if (!(*out).is_open()) {
		std::cout << "Файл для чтения не найден!" << std::endl;
		f = 0;
	}

	return f;
}