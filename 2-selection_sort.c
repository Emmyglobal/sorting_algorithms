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
	size_t i, j, smallest;
	int temp, swap_flag;

	for (i = 0; i  < size; i++)
	{
		smallest = i;
		swap_flag = 0;
		for (j = i; j  < size; j++)
		{
			if (array[smallest] > array[j])
			{
				swap_flag = 1;
				smallest = j;
			}
		}
		if (i != smallest)
		{
		temp = array[i];
		array[i] = array[smallest];
		array[smallest] = temp;
		print_array(array, size);
		if (swap_flag == 0)
			return;
		}
	}
}
