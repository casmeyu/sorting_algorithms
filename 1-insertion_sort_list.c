#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - sorts a ddouble linked list with insertion sort algo
 *
 * It goes element by element comparing it with the previous one.
 * if it is smaller it swaps them
 *
 * @list: head node of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *aux;

	if (!(*list) || !(*list)->next)
		return;

	tmp = (*list)->next;
	aux = tmp;

	while (tmp)
	{
		aux = tmp->next;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			/* change around node */
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;

			/* change node position */
			tmp->next = tmp->prev;
			if (tmp->next)
			{
				tmp->prev = tmp->next->prev;
				tmp->next->prev = tmp;
			}
			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				(*list) = tmp;

			print_list(*list);

		}
		tmp = aux;

	}
}
