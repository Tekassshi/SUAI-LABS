// var12

#include <iomanip>
#include <iostream>

void table(double x, double y, bool e)
{
	std::cout << std::right << std::setw(10) << std::setfill(' ') << x << "|";

	if (e)
	{
		std::cout << std::right << std::setw(11) << std::setfill(' ') << "-|" << std::endl;
	}
	else
	{
		std::cout << std::right << std::setw(10) << std::setfill(' ') << std::setprecision(3) << y << "|" << std::endl;
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
	std::cout << "Введите значение ""X-нач"": "; std::cin >> xstart;
	std::cout << "Введите значение ""X-кон"": "; std::cin >> xend;

	std::cout << std::endl;
	std::cout << std::right << std::setw(11) << std::setfill(' ') << "x|";
	std::cout << std::right << std::setw(11) << std::setfill(' ') << "y|" << std::endl;
	std::cout << std::right << std::setw(22) << std::setfill('_') << "" << std::endl << std::endl;

	for (i = xstart; i <= xend; i += dx)
	{
		if ((i < 0.6) && (b+c != 0))
		{
			table(i, a * pow(i, 3) + b * b + c, 0);
		}
		else if ((i > 0.6) && (b + c == 0))
		{
			if (i - c != 0)
			{
				table(i, (i - a) / (i - c), 0);
			}
			else
			{
				table(i, (i - a) / (i - c), 1);
			}
		}
		else
		{
			if (c == 0 || a == 0)
			{
				table(i, (i - a) / (i - c), 1);
			}
			else
			{
				table(i, i / c + i / a, 0);
			}
		}
	}
}