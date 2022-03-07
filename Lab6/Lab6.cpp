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
#include "functions.h";

int main() {

	setlocale(LC_ALL, "rus");

	int k, i, m, n;
	double l, sumstr = 0, sumcol = 0;

	std::cout << "Введите размерность матрицы (кол-во строк, столбцов): ";
	std::cin >> m >> n;

	// Создание двумерной матрицы
	double** array = new double* [m];

	for (i = 0; i < m; i++) {
		array[i] = new double[n];
	}

	// Заполнение двумерной матрицы
	std::cout << "Введите свою матрицу:" << std::endl;

	for (i = 0; i < m; i++) {
		for (k = 0; k < n; k++) {
			std::cin >> l;
			array[i][k] = l;
		}
		std::cout << std::endl;
	}

	// Нахождение первой строки, содержащей хотя бы один положительный элемент
	bool f = 0;
	for (i = 0; i < m; i++) {
		for (k = 0; k < n; k++) {
			if (array[i][k] > 0) {
				std::cout << "Номер первой строки, содержащей положительный элемент: " << i << std::endl;
				f = 1;
				break;
			}
		}
		if (f == 1) { break; }
	}

	//Считаем количество нулевых строк
	for (i = 0; i < m; i++) {
		if (sum(array, i, n, 1) == 0) {
			sumstr += 1;
		}
	}

	//Считаем количство нулевых столбцов
	for (i = 0; i < n; i++) {
		if (sum(array, m, i, 0) == 0) {
			sumcol += 1;
		}
	}

	//Выделение памяти для сжатой матрицы (c учетом удаленных элементов)

	int m1 = m - sumstr, n1 = n - sumcol;

	double** newarray = new double* [m1]; 

	for (i = 0; i < m1; i++) {
		newarray[i] = new double[n1];
	}

	// Сжатие матрицы
	compress(array, m, n, newarray, m1, n1);

	//Вывод сжатой матрицы
	for (i = 0; i < m1; i++) {
		for (k = 0; k < n1; k++) {
			std::cout << newarray[i][k] << " ";
		}
		std::cout << std::endl;
	}

	//Очистка памяти
	
	//Очистка старого массива
	for (i = 0; i < m; i++) {
		delete[] array[i];
	}
	delete[] array;

	//Очистка нового массива
	for (i = 0; i < m1; i++) {
		delete[] newarray[i];
	}
	delete[] newarray;

	// Для обнаружения утечек памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
}