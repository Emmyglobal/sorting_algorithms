#include "sort.h"
#include <stdio.h>

/**
 * shell_sort -> Function that sorrs arrays of integer
 * in ascending order using tge shell sort algorithm
 * using the knoth sequence
 * @array: List of integers
 * @size: Length of array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t j, gap, i;
	int temp;

	gap = 1;
	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
