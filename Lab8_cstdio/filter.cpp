#include <iostream>
#include <cstdio>
#include "functions.h"

void filter(FILE* input_file, FILE* output_file, char symbarr[]) {

	// fs - flag symbol  (Показательтого, что мы записываем новое предложение)
	// fe - flag end     (Флаг переноса спец. символа на следующую строку)

	bool fs = 0, fe = 0;
	char symb;

	while ((symb = fgetc(input_file)) != EOF) {

		// Для записи троеточия 
		if (fe == 1 && symb == '.') {
			fputc(symb, output_file);
			fputc(symb, output_file);
			fputc(' ', output_file);
			fe = 0;
			continue;
		}

		if (iscontains(symbarr, symb) && fs == 1) {
			fe = 1;
		}

		if (symb == '-') {
			fs = 1;
		}

		if (fs == 1 && fe == 0) {
			fputc(symb, output_file);
		}
		else if ((fs == 1 && fe == 1) || (symb == '\n')) {
			fputc(symb, output_file);
			if (symb != '\n' && symb != '.') {
				fputc(' ', output_file);
			}
			if (symb != '.') { 
				fe = 0; 
			}
			fs = 0;
		}
	}
}