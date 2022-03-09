//Сохранить входные данные, правильно использовать указатели
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

; int main()
{
	setlocale(LC_ALL, "rus");

	int i, n;
	double num, a, b;
	bool check = 1;
	
	std::cout << "Введите длину массива: "; std::cin >> n;
	std::cout << "Вводите элементы массива по порядку: \n";

	double * array = new double[n];
	double * transformed = new double[n];

	for (i = 0; i < n; i++)
	{
		std::cin >> array[i];
		/*array[i] = num;*/
	}

	std::cout << std::endl;
	std::cout << "\n" << "Номер максимального по модулю элемента: " << automax(array, n);

	//Добавление проверки по переменной bool check
	sum(array, n, check);

	if (check == 0) {
		std::cout << "\n"  << "Невозможно посчитать сумму" << std::endl;
	}
	else {
		std::cout << "\n" << "Cумма модулей, расположенных после первого положительного элемента: " << sum(array, n, check) << std::endl;
	}

	std::cout << "Введите интервал (a, b): ";
	std::cin >> a; std::cin >> b; std::cout << std::endl;

	transform(array, transformed, n, a, b);

	std::cout << "Введённый массив: " << std::endl << " ";

	for (i = 0; i < n; i++)
	{
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
	std::cout << "Преобразованный массив: " << std::endl << " ";

	for (i = 0; i < n; i++)
	{
		std::cout << transformed[i] << " ";
	}

	delete[] array;
	delete[] transformed;

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

// Добавить проверку на отрицательную длину массива

// Добавить в функцию sum bool по указателю
// Добавил проверку на наличие положительных чисел в массиве, 
// bool check передаётся по ссылке