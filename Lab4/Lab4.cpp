// var12

#include <iomanip>
#include <iostream>
#include <cmath>

double table(double i, double a, double b, double c, bool &f)
{

	if ((i < 0.6) && (b + c != 0))
	{
		f = 0;
		return a * pow(i, 3) + b * b + c;
	}
	else if ((i > 0.6) && (b + c == 0))
	{
		if (i - c != 0)
		{
			f = 0;
			return (i - a) / (i - c);
		}
		else
		{
			f = 1;
			return 0;
		}
	}
	else
	{
		if (c == 0 || a == 0)
		{
			f = 1;
			return 0;
		}
		else
		{
			f = 0;
			return i / c + i / a;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	double i, a, b, c, xstart, xend, dx;

	std::cout << "Введите значение ""a"": ";	 std::cin >> a;
	std::cout << "Введите значение ""b"": ";	 std::cin >> b;
	std::cout << "Введите значение ""c"": ";	 std::cin >> c;
	std::cout << "Введите значение ""dx"": ";    std::cin >> dx;
	while (dx <= 0)
	{
		std::cout << "Введите шаг корректно: " << std::endl;
		std::cin >> dx;
	}
	std::cout << "Введите значение ""X-нач"": "; std::cin >> xstart;
	std::cout << "Введите значение ""X-кон"": "; std::cin >> xend;

	std::cout << std::endl;
	std::cout << std::right << std::setw(11) << std::setfill(' ') << "x|";
	std::cout << std::right << std::setw(11) << std::setfill(' ') << "y|" << std::endl;
	std::cout << std::right << std::setw(22) << std::setfill('_') << "" << std::endl << std::endl;

	bool f = 0;

	double eps = dx/2;

	for (i = xstart; i <= xend + eps; i += dx)
	{
		std::cout << std::right << std::setw(10) << std::setfill(' ') << i << "|";
		double result = table(i, a, b, c, f);

		if (f)
		{
			std::cout << std::right << std::setw(11) << std::setfill(' ') << "-|" << std::endl;
		}
		else
		{
			std::cout << std::right << std::setw(10) << std::setfill(' ') << std::setprecision(3) << result << "|" << std::endl;
		}
	}
}

/*
* 
Ошибка точности представления чисел в ЭВМ :

Введите значение a : 1
Введите значение b : 2
Введите значение c : 3
Введите значение dx : 0.001
Введите значение X - нач : 0.01
Введите значение X - кон : 0.02

При прибавлении к счётчику, dx представляется не как 0.001, а как 0.000999...
Следовательно, последнее значение 0.02 не достигается.

Чтобы исправить это, мы прибавляем к последнему значению погрешность eps = 0.0001, 
которая возникает вследствие неправильного представления чисел это позволяет нам
достигнуть последнего значения 0.02

*/
