// Функция для проверки, содержит ли массив символ

bool iscontains(char symbarr[], char symb) {
	int i;
	bool f = 0;

	for (i = 0; i < (sizeof(symbarr) / sizeof(symbarr[0])); i++) {
		// условие (symb < 'А') || (symb > 'Я') для отсечения больших русских букв, так как их отрицательные
		// коды пересекаются со спец символами из массива
		if ((symbarr[i] == symb) && ((symb < 'А') || (symb > 'Я'))) {
			f = 1;
			break;
		}
	}

	return f;
}