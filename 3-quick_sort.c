#include <stdio.h>
#include "sort.h"

/*
 * quick_sort -> Sorts array of int in ascending order using Quick sort
 * @array: Array of integers to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, size - 1, size);
}


/**
 * sort -> a recursive inline function for sorting the array
 * @low: lowest index
 * @high: highest index
 *
 * Return: Nothing
 */

void sort(int *array, int low, int high, int size)
{
	int k, i, j, pivot, temp, index_of_pivot;


	/* base case */
	if (low >= high)
		return;
	
	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	index_of_pivot = i + 1;

	for (k = 0; k < size; k++)
	{
		if (k < size - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
	}

	sort(array, low, index_of_pivot - 1, size);
	sort(array, index_of_pivot + 1, high, size);
}
