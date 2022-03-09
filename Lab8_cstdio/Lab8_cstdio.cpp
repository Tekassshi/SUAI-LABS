//Lab 8 with <cstdio> using

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
#include <cstdio>

int main() {
	setlocale(LC_ALL, "rus");

	// fs - flag symbol       (Показательтого, что мы записываем новое предложение)
	// fe - flag end          (Флаг переноса спец. символа на следующую строку)
	// f - флаг начала чтения (для первого предложения)

	bool fs = 0, fe = 0, f = 0, fd = 0;

	char symb;

	int k = 0;

	FILE* input_file = NULL;
	FILE* output_file = NULL;

	fopen_s(&input_file, "input.txt", "r");
	fopen_s(&output_file, "output.txt", "w");

	/*
	Проверяем строку на заданный шаблон, если предложение начинается с тире,
	то мы записываем в файл output.txt
	*/

	while ((symb = fgetc(input_file)) != EOF) {

		// Для переноса на новую строку
		if ((f == 1) && (fe == 1) && (symb == '\n' || symb == '.')) {
			fputc(symb, output_file);
			fe = 0;
			fs = 0;
		}

		if (symb == '-') {
			fs = 1;
		}

		if (fs == 1) {
			fputc(symb, output_file);
			f = 1;
		}

		if (symb == '.' || symb == '!' || symb == '?') {
			fs = 0;
			fe = 1;
		}
	}

	fclose(input_file);
	fclose(output_file);

	// Для обнаружения утечек памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	return 0;
}

//Добавить проверку на существование файла и открыт ли он