#include <iostream>

void transform(char* str, char* outstring, int size, int expsize, int spaces) {
	int i, k = 0, j, plus = 0, mid = 0, ost = 0;

	plus = expsize - size;  // Количество пробелов, которые нужно добавить
	mid = plus / spaces;    // Среднее кол-во пробелов, которое необходимо добавить
	ost = plus % spaces;

	// k - счётчик для нового массива
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

	// Заполняем остатки пробелов начиная с нуль-терминатора
	k -= 1;

	for (j = 0; j < ost; j++) {
		outstring[k] = ' ';
		std::cout << outstring[k];
		k += 1;
	}

	// Устанавливаем новый нуль-терминатор
	outstring[expsize - 1] = '\0';
}