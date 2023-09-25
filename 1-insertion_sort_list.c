#include <stddef.h>
#include "sort.h"

/**
* insertion_sort_list - an implimentation of insertion
 * sorting algorithm
* @list: the linked list to be sorted
* Return: NULL
*/
void insertion_sort_list(listint_t **list)
{
	size_t i, j;
	listint_t *temp, *temp2;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	temp2 = (*list)->next;
	for (i = 1; temp2 != NULL; i++)
	{
		j = 0;
		temp = temp2;
		temp2 = temp2->next;
		while (j != i && temp->prev != NULL)
		{
			i += 1;
			if (temp->prev->n > temp->n)
			{
				temp->prev->next = temp->next;
				temp->next = temp->prev;
				temp->prev = temp->prev->prev;
				temp->next->prev = temp;
				if (temp->prev != NULL)
					temp->prev->next = temp;
				if (temp->next->next != NULL)
					temp->next->next->prev = temp->next;
				if (temp->prev == NULL)
					*list = temp;
				print_list(*list);
			}
			else
				break;
		}
	}
}
