#include "sort.h"
#include <stdio.h>
/**
 * selection_sort - sort an array of integers with sort insert
 *
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t idx_arr, idx_sort;
	int aux;

	printf("entered function\n");

	for (idx_arr = 0; idx_arr < (size - 1); idx_arr++)
	{
		for (idx_sort = idx_arr; idx_sort < size; idx_sort++)
		{
			if (array[idx_sort] < array[idx_arr])
			{
				aux = array[idx_sort];
				array[idx_sort] = array[idx_arr];
				array[idx_arr] = aux;
				print_array(array, size);
			}
		}
	}
	(void) array;
	(void) size;
}
