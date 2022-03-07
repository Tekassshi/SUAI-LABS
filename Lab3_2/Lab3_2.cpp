#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	unsigned short a;

	std::cout << "Введите 16-ный код структуры: ";
	std::cin >> std::hex >> a;

	if (((a & 0x1) == 0) && (((a >> 8) & 0xff) == 0xc6))
	{
		std::cout << std::endl;
		std::cout << "Первый операнд: " << ((a >> 4) & 0x7) << std::endl;
		std::cout << "Второй операнд: " << ((a >> 1) & 0x7) << std::endl;
		std::cout << "Тип операндов (0 – байты, 1 - слова): " << ((a >> 7) & 0x1) << std::endl;
	}
	else 
	{
		std::cout << "Структура введена некорректно";
	}
}