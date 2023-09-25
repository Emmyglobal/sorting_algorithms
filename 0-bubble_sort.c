#include <stdio.h>
#include "sort.h"

/**
* bubble_sort - this function impliments bubble sort algorithm
 * after each swap the curent the curent array is printed
* @array: the array of integers to be sorted
* @size: size of the array
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swap_flag;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swap_flag = 0;
		for (j = 0; j + 1 < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_flag = 1;
				print_array(array, size);
			}

		}
		if (swap_flag == 0)
			return;
	}
}
