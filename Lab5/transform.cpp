void transform(double*& array, int& arrsize, double a, double b)
{
	double* temp = new double[*&arrsize];

	int i, k = 0;

	for (i = 0; i < *&arrsize; i++)
	{
		if (array[i] >= a && array[i] <= b)
		{
			temp[k] = array[i];
			k++;
		}
	}
	for (i = 0; i < *&arrsize; i++)
	{
		if (array[i] < a || array[i] > b)
		{
			temp[k] = array[i];
			k += 1;
		}
	}

	delete[] * &array;
	*&array = temp;
}