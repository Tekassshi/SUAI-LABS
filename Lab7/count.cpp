/*
	������� ������� ���������� �������� � ���� � �������� ������.
	��������� spaces, words ���������� �� ������.
*/

void count(char* str, int size, int* spaces, int* words) {
	int i;
	for (i = 0; i < size; i++) {
		if (str[i] == ' ') {
			*spaces += 1;
		}
	}

	*words = *spaces + 1;
}