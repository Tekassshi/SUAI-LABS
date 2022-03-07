// ������ �������
/*
	�������� �� ��������� �������, � ���� ������/������� ������� �� �����,
	�� ������ ���������� ��, ���������� ������� ��������� ����� �������,
	� ������ ����� ���������� ����������� ��������. ����� ������ �� ���,
	����� ������� ����� ������� �� ����� �� � �������.
*/

#include "functions.h";

void compress(double** array, int m, int n, double** newarray, int m1, int n1) {
	int i, k;            // �������� ��� ������ �������
	int i1 = 0, k1 = 0;  // ������� ��� ����� �������

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