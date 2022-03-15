#include <cmath>;

double sum(double*& array, int& arrsize)
{
	double sum = 0;
	int i, f = 0;

	for (i = 0; i < *&arrsize; i++)
	{
		if (f == 1)
		{
			sum += abs(array[i]);
		}

		if (array[i] > 0)
		{
			f = 1;
		}

	}

	return sum;
}