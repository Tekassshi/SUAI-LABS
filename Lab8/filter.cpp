#include <iostream>
#include "functions.h"

void filter(std::ifstream* in, std::ofstream* out, char symbarr[]) {
	int l;
	std::string word;
	bool fw = 0;      // flag word (Показатель того, что текущее предложение начинается с тире)

	while (!(*in).eof()) {
		*in >> word;
		l = word.length();

		if (word[0] == '-') {
			fw = 1;
		}

		if (fw == 1) {
			*out << word << " ";
		}

		if (iscontains(symbarr, word[l - 1])) {
			fw = 0;
		}
	}
}