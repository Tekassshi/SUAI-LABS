//Lab 8 with <fstream> using

#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

int main() {
	setlocale(LC_ALL, "rus");

	char symbarr[] = { '.', '!', '?'};

	std::ifstream in;
	std::ofstream out;
	
	in.open("input.txt");
	out.open("output.txt");

	if (!fisopen(&in, &out)) {
		return 0;
	}

	/*
	Проверяем строку на заданный шаблон, если предложение начинается с тире, 
	то мы записываем в файл output.txt
	*/

	filter(&in, &out, symbarr);

	in.close();
	out.close();

	return 0;
}