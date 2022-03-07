void transform(double array[], double transformed[], int arrsize, double a, double b)
{
	int i, k = 0;

	for (i = 0; i < arrsize; i++)
	{
		if (array[i] >= a && array[i] <= b)
		{
			transformed[k] = array[i];
			k++;
		}
	}
	for (i = 0; i < arrsize; i++)
	{
		if (array[i] < a || array[i] > b)
		{
			transformed[k] = array[i];
			k += 1;
		}
	}
}