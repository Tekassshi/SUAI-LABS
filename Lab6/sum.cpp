// C���� ���� ������/������� (bool b: 1 - ������, 0 - �������)
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
