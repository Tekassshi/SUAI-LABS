// ������� ��� ��������, �������� �� ������ ������

bool iscontains(char symbarr[], char symb) {
	int i;
	bool f = 0;

	for (i = 0; i < (sizeof(symbarr) / sizeof(symbarr[0])); i++) {
		// ������� (symb < '�') || (symb > '�') ��� ��������� ������� ������� ����, ��� ��� �� �������������
		// ���� ������������ �� ���� ��������� �� �������
		if ((symbarr[i] == symb) && ((symb < '�') || (symb > '�'))) {
			f = 1;
			break;
		}
	}

	return f;
}