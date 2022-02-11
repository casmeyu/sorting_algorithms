#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - sorts a ddouble linked list using insertion sort algorightm
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
		printf("Entered while with: %d\n", tmp->n);
		aux = tmp->next;
		while (tmp->n < tmp->prev->n && tmp->prev)
		{
			printf("%d is less than %d\n", tmp->n, tmp->prev->n);
			/* change around node */
			printf("changing around node\n");
			tmp->prev->next = tmp->next;
			print_list(*list);
			tmp->next->prev = tmp->prev;

			/* change node position */
			printf("changing node position\n");
			
			tmp->prev = tmp->prev->prev;
			tmp->next = tmp->prev->next;
			
			printf("putting myself int\n");
			tmp->prev->next = tmp;

			tmp->next->prev = tmp;
			print_list(*list);
			tmp = aux;
		}
		tmp = tmp->next;
	}

}
