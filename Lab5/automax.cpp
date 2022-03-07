#include <cmath>;

double automax(double array[], int arrsize)
{
	int i, k = 0;
	double max;

	max = array[0];

	for (i = 0; i < arrsize; i++)
	{
		if (abs(array[i]) > max)
		{
			max = abs(array[i]);
			k = i;
		}
	}

	return k;
}