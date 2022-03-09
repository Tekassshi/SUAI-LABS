//Lab 8 with <fstream> using

#include <iostream>
#include <fstream>
#include <string>

int main() {
	setlocale(LC_ALL, "rus");

	bool fw = 0; // flag word (Показатель того, что текущее предложение начинается с тире)
	int i, k, j, l;
	std::string word, s, s1, s2;

	std::ifstream in;
	std::ofstream out;
	
	in.open("input.txt");
	out.open("output.txt");

	/*
	Проверяем строку на заданный шаблон, если предложение начинается с тире, 
	то мы записываем в файл output.txt
	*/

	while (!in.eof()) {
		in >> word;
		l = word.length();

		if (word[0] == '-') {
			fw = 1;
		}

		if (fw == 1) {
			out << word << " ";
		}

		if (word[l-1] == '.' || word[l - 1] == '?' || word[l - 1] == '!') {
			fw = 0;
		}
	}

	in.close();
	out.close();

	return 0;
}

// Добавить массив символов окончания предложения
// Создать функцию с указателем на файл