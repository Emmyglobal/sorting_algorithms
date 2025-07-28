#include "deck.h"

/**
 * sort_deck -> Sorts a deck of cards
 * @deck: the deck of cards
 *
 * Return: Nothing
 */

void sort_deck(deck_node_t **deck)
{
	int swapped;
	deck_node_t *curr;

	if (!deck || !*deck || !(*deck)->next)
		return;


	do {
		swapped = 0;
		curr = *deck;

		while(curr->next)
		{
			if (compare_cards(curr, curr->next) > 0)
			{
				
				/* swap nodes */
				deck_node_t *first = curr;
				deck_node_t *second = curr->next;
				
				first->next = second->next;
				
				if (second->next)
					second->next->prev = first;
				
				second->prev = first->prev;
				
				if (first->prev)
					first->prev->next = second;
				else
					*deck = second;
				
				second->next = first;
				first->prev = second;
				
				swapped = 1;
			}
			else
				curr = curr->next;
		}
	}
	while (swapped);
}

/**
 * card_value -> Assigns a numeric rank to each card
 * @value: Value to be assigned
 *
 * Return: integer value
 */
int card_value(const char *value)
{
	if (strcmp(value, "Ace") == 0)
		return 1;
	if (strcmp(value, "Jack") == 0)
		return 11;
	if (strcmp(value, "Queen") == 0)
		return 12;
	if (strcmp(value, "King") == 0)
		return 13;
	return atoi(value);
}

/**
 * compare_cards -> Compares the cards
 * @a: first card
 * @b: second card
 *
 * Return: Nothing
 */
int compare_cards(const deck_node_t *a, const deck_node_t *b)
{
	if (a->card->kind != b->card->kind)
		return a->card->kind - b->card->kind;

	return card_value(a->card->value) - card_value(b->card->value);
}
