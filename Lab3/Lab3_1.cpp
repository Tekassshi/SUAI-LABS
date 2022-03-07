#include <iostream>

int check(int r)
{
	int a;
	std::cin >> a;

	while ((a > r) || (a < 0))
	{
		std::cout << "Введеный операнд не помещается в разрядную сетку, повторите ввод. " << std::endl << "Введите число меньшее " << r << std::endl;
		std::cin >> a;
	}

	return a;
}

int main()
{
	setlocale(LC_ALL, "rus");

	unsigned short res = 0;
	unsigned int a, b, d;

	std::cout << "Введите первый операнд: ";
	a = check(0x7);
	std::cout << "Введите второй операнд: ";
	b = check(0x7);
	std::cout << "Введите тип операндов (0 - байты, 1 - слова): ";
	d = check(1);

	res = (b << 1) | (a << 4) | (d << 7) | (0xc6 << 8);
	std::cout << std::hex << res;
}