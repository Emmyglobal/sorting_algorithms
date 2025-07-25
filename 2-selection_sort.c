#include <stddef.h>
#include "sort.h"

/**
* selection_sort - an implimentation of selection sort algorithm
* @array: the array to be sorted
* @size: size of the array
* Return: NULL
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min_index = i;
		/* Find index of the minimum element in the unsorted */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		 /* swap if needed */
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
