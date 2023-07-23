#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: double pointer to the head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *tail = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do
	{
		swapped = 0;
		current = *list;

		while (current->next != tail)
		{
			if (current->n > current->next->n)
			{
				switch_nodes(list, current, current->next);
				print_list(*list);
					swapped = 1;
			} else
			{
				current = current->next;
			}
		}

		if (swapped == 0)
			break;

		tail = current;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				switch_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			} else
			{
				current = current->prev;
			}
		}
	} while (swapped);
}

/**
 * switch_nodes - Switches two nodes in a doubly linked list
 * @list: double pointer to the head of the list
 * @n1: first node
 * @n2: second node
 */

void switch_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*list = n2;

	if (n2->next != NULL)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;
	n2->next = n1;
	n1->prev = n2;
}
