// Cумма цифр строки/столбца (bool b: 1 - строка, 0 - столбец)
double sum(double** array, int m, int n, bool b) {
	int i;
	double sum = 0;

	if (b) {
		for (i = 0; i < n; i++) {
			sum += array[m][i];
		}
	}
	else {
		for (i = 0; i < m; i++) {
			sum += array[i][n];
		}
	}

	return sum;
}