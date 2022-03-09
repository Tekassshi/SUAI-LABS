#include <string>

std::string* split(std::string s) {
	int i, sum = 1, k = 0;
	std::string s1 = "";

	//Определяем количество слов
	for (i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			sum += 1;
		}
	}
	s += " ";

	std::string* array = new std::string[sum];

	for (i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			s1 += s[i];
		}
		else {
			array[k] = s1;
			s1 = "";
			k += 1;
		}
	}

	return array;
}