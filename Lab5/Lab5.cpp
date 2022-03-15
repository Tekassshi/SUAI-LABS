// Для обнаружения утечек памяти
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif


// Основной код
#include <iostream>
#include "functions.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int i, n;
	double num, a, b;

	std::cout << "Введите длину массива: "; std::cin >> n;
	std::cout << "Вводите элементы массива по порядку: \n";

	double* array = new double[n];

	for (i = 0; i < n; i++)
	{
		std::cin >> num;
		array[i] = num;
	}

	std::cout << std::endl;
	std::cout << "\n" << "Номер максимального по модулю элемента: " << automax(array, n);
	std::cout << "\n" << "Cумма модулей, расположенных после первого положительного элемента: "<< sum(array, n) << std::endl;

	std::cout << "Введите интервал (a, b): ";
	std::cin >> a; std::cin >> b; std::cout << std::endl;

	transform(array, n, a, b);

	std::cout << "Преобразованный массив: " << std::endl << " ";

	for (i = 0; i < n; i++)
	{
		std::cout << array[i] << " ";
	}

	delete[] array;

	std::cout << std::endl << "\n";

	// Для обнаружения утечек памяти
	_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
	_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );
	_CrtDumpMemoryLeaks();
}