// var 12

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>;
bool check(double x, double y)
{
	if (((y >= 0) && (x <= 1) && (y <= 1) && (x >= -1)) ||
		((y <= 0) && (pow(x, 2) + pow(y, 2) <= 1))) 
	{
		return true;
	}
	else
{
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	double x, y;

	std::cout << "Введите координаты точки (x, y) через пробел: ";
	scanf("%lf%lf", &x, &y);

	/*std::cin >> x >> y;
	std::cout << std::endl;*/

	if (check(x, y)){

		printf("Точка (%.2lf; %.2lf) попадает в заштрихованную область", x, y);
	}
	else
	{
		printf("Точка (%.2lf; %.2lf) не попадает в заштрихованную область!", x, y);
	}

	std::cout << std::endl;
}