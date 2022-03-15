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
#include "functions.h"

int main() {
	setlocale(LC_ALL, "rus");

	char symbarr[] = {'.', '!', '?', '\n'};
	
	FILE* input_file = NULL;
	FILE* output_file = NULL;

	fopen_s(&input_file, "input.txt", "r");
	fopen_s(&output_file, "output.txt", "w");
	
	if (!fisopen(input_file, output_file)) {
		return 0;
	}

	/*
	Проверяем строку на заданный шаблон, если предложение начинается с тире,
	то мы записываем в файл output.txt
	*/

	filter(input_file, output_file, symbarr);

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