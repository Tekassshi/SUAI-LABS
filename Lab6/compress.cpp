// Сжатие матрицы
/*
	Проходим по начальной матрице, и если строка/столбец состоят из нулей,
	то просто пропускаем их, остальными данными заполняем новую матрицу,
	и только после заполнения увеличиваем счетчики. Также следим за тем,
	чтобы индексы новой матрицы не вышли за её пределы.
*/

#include "functions.h";

void compress(double** array, int m, int n, double** newarray, int m1, int n1) {
	int i, k;            // счётчики для старой матрицы
	int i1 = 0, k1 = 0;  // счётчки для новой матрицы

	for (i = 0; i < m; i++) {
		if (i1 < m1) {
			if (sum(array, i, n, 1) == 0) {
				continue;
			}
			for (k = 0; k < n; k++) {
				if (k1 < n1) {
					if (sum(array, m, k, 0) == 0) {
						continue;
					}
					newarray[i1][k1] = array[i][k];
					k1 += 1;
				}
				else {
					break;
				}
			}
			i1 += 1;
			k1 = 0;
		}
		else {
			break;
		}
	}
}