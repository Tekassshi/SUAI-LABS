// ������� ��� �������� ������������� � �������� �����

#include <fstream>
#include <iostream>

// �������� ������ �� ���������, �� ��� ���� ��� ������

bool fisopen(std::ifstream* in, std::ofstream* out) {
	bool f = 1;

	if (!(*in).is_open()) {
		std::cout << "���� ��� ������ �� ������!" << std::endl;
		f = 0;
	}
	if (!(*out).is_open()) {
		std::cout << "���� ��� ������ �� ������!" << std::endl;
		f = 0;
	}

	return f;
}