#include <iostream>

void transform(char* str, char* outstring, int size, int expsize, int spaces) {
	int i, k = 0, j, plus = 0, mid = 0, ost = 0;

	plus = expsize - size;  // ���������� ��������, ������� ����� ��������
	mid = plus / spaces;    // ������� ���-�� ��������, ������� ���������� ��������
	ost = plus % spaces;

	// k - ������� ��� ������ �������
	for (i = 0; i < size; i++) {
		outstring[k] = str[i];
		k += 1;

		if (str[i] == ' ') {
			for (j = 0; j < mid; j++) {
				outstring[k] = ' ';
				k += 1;
			}
		}
	}

	// ��������� ������� �������� ������� � ����-�����������
	k -= 1;

	for (j = 0; j < ost; j++) {
		outstring[k] = ' ';
		std::cout << outstring[k];
		k += 1;
	}

	// ������������� ����� ����-����������
	outstring[expsize - 1] = '\0';
}