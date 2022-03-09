/*
	������� ���� ����������, ������� ����� ���������� ��� ����� ������ ��� ������,
	� ����� ������������ ���������� ���� ���������, �������� ������� �� ������ ������ �������,
	� ��� �������� "1" � ������� main(), ��������� ��������� ������.
*/

#include <iostream>

void exceptions(bool* fpointer1, bool* fpointer2, char* str, char* outstring, int size, int expsize) {
	if (strlen(str) != (size - 1)) {
		std::cout << std::endl;
		std::cout << "�������� ������ �� ������������� ��������� �������!";
		std::cout << std::endl;
		delete[] str;
		delete[] outstring;
		*fpointer1 = 1;
	}
	else if (expsize <= size) {
		std::cout << std::endl;
		std::cout << "� ����� ������ ��� ���������� ��������!";
		std::cout << std::endl;
		delete[] str;
		delete[] outstring;
		*fpointer2 = 1;
	}
}