// ������� �������� �� ������� ������

#include <cstdio>
#include <iostream>

bool fisopen(FILE* input_file, FILE* output_file) {

	bool f = 1;

	if (input_file == NULL) {
		std::cout << "���� ��� ������ �� ����������!";
		f = 0;
	}

	if (output_file == NULL) {
		std::cout << "���� ��� ������ �� ����������!";
		f = 0;
	}

	return f;
}