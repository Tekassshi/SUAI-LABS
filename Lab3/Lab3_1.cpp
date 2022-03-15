#include <iostream>

int check(bool b)
{
	int a;
	while (true)
	{
		std::cin >> a;
		if (b)
		{
			if (a == 1 || a == 0)
			{
				return a;
			}
			else
			{
				std::cout << "Введеный операнд не помещается в разрядную сетку, повторите ввод.\n";
			}
		}
		else if (a > 0x7)
		{
			std::cout << "Введеный операнд не помещается в разрядную сетку, повторите ввод.\n";
		}
		else
		{
			std::cout << "\n";
			return a;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	unsigned short res = 0;
	int a, b, d;

	std::cout << "Введите первый операнд: ";
	a = check(0);
	std::cout << "Введите второй операнд: ";
	b = check(0);
	std::cout << "Введите тип операндов (0 - байты, 1 - слова): ";
	d = check(1);

	res = (b << 1) | (a << 4) | (d << 7) | (0xc6 << 8);
	std::cout << std::hex << res;
}