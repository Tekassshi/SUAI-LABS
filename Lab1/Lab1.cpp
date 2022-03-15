// Var 12

#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");

	double a1, a2, z1, z2, pi = 355.0 / 113;
	double rad;

	std::cout << "Введите значение угла для выражений: ";
	std::cin >> a1;

	// рад = Pi/180 * x

	rad = (pi / 180) * a1;

	z1 = (sin(4 * rad) / (1 + cos(4 * (rad)))) * (cos(2 * rad) /
		(1 + cos(2 * (pi / 180) * a1)));
	z2 = cos((3.0 / 2 * pi) - (rad)) / sin((3.0 / 2 * pi) - (rad));
	
	/*std::cout << "z1 = " << z1 << std::endl;
	std::cout << "z2 = " << z2 << std::endl;*/

	printf("z1 = %.10lf \n", z1);
	printf("z2 = %.10lf", z2);
}