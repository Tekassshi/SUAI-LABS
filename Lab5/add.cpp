//функция добавления элемента в конец массива;

void add(double*& array, double a, int& arrsize)
{
	int i;
	double* temp = new double[*&arrsize + 1];

	for (i = 0; i < arrsize + 1; i++)
	{
		if (i == *&arrsize)
		{
			temp[i] = a;
		}
		else
		{
			temp[i] = array[i];
		}
	}

	delete[] * &array;

	*&array = temp;
	*&arrsize += 1;
}