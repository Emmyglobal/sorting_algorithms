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
	listint_t *next_current, *current, *temp, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_current = current->next;
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap temp and temp->prev */
			prev = temp->prev;
			next = temp->next;

			/* Detatch temp */
			if (prev->prev)
				prev->prev->next = temp;
			temp->prev = prev->prev;

			/* Reconnect temp before prev */
			temp->next = prev;
			prev->prev = temp;

			/* Reconnect prev to next */
			prev->next = next;
			if (next)
				next->prev = prev;

			/* update head if needed */
			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}
		current = next_current;
	}
}
