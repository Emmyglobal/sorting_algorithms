#include "sort.h"

size_t split(int *ar, int start, int s)
{
	int i, j, piv, temp, dif = s - start;

	piv = (dif % 2 == 0) ? dif / 2 : (dif - 1) / 2;
	piv = start + piv;
	printf("%d \n", ar[piv]);
	for (i = start; i < piv; i++)
	{
	
		if (ar[i] > ar[piv])
		{
			for (j = 0; j < piv; j++)
			{
				if (ar[s - 1 - j] < ar[piv])
				{
					temp = ar[i];
					ar[i] = ar[s - 1 -j];
					ar[s - 1 - j] = temp;
					break;
				}
			}
			printf("%d - %d\n", j, piv);
			if (j == piv)
			{
				temp = ar[piv];
				ar[piv] = ar[i];
				ar[i] = temp;
				break;
			}
		}
	}
	for (j = 0; i + j < s; j++)
	{
		printf("%d - %d\n", ar[i+j],ar[i]);
		if (ar[i + j] < ar[i])
		{
			temp = ar[i];
			ar[i] = ar[i + j];
			ar[i + j] = temp;
			i = i + j;
			j = 0;
		}
	}
	return (i);
}

/**
* quick_sort - an implimentation of quick sort algorithm
* @array: the array to be sorted
* @size: the size of the array
* Return: NULL
*/
void quick_sort(int *array, size_t size)
{
	size_t i, mid;

	if (size < 2)
		return;
	mid = split(array, size);
	quick_sort(array, mid);
}
