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
	listint_t *tmp;
	int end = 0;
/*
	if (!(*list) || !(*list)->next)
		return (void);
*/
	printf("assigned tmp\n");
	while (end == 0)
	{
		tmp = (*list)->next;
		while (tmp)
		{
			end = 1;
			if (tmp->n < tmp->prev->n)
			{
				end = 0;
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
/*				printf("changed around node\n");*/
				if (tmp->prev->prev)
					tmp->prev->prev->next = tmp;
				printf("1\n");
				tmp->next = tmp->prev;
			
				print_list(*list);/*
				printf("changed node");*/

				break;
			}
			tmp = tmp->next;
		}
	}

}
