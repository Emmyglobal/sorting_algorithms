#include <stdio.h>
#include "sort.h"

/**
* bubble_sort - this function impliments bubble sort algorithm
 * after each swap the curent array is printed
* @array: the array of integers to be sorted
* @size: size of the array
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, x;
	int temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			
			for (x = 0; x < size; x++)
			{
				printf("%d", array[x]);
				if (x == size - 1)
					printf("\n");
				else
					printf(", ");
			}}
		}
	}
}
