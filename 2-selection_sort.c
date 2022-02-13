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
	size_t idx_arr, idx_min, idx_sort;
	int aux, flag;

	if (!array || size < 2)
		return;

	for (idx_arr = 0; idx_arr < size; idx_arr++)
	{
		idx_min = idx_arr;
		flag = 0;
		for (idx_sort = idx_arr + 1; idx_sort < size; idx_sort++)
		{
			if (array[idx_sort] < array[idx_min])
			{
				idx_min = idx_sort;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			aux = array[idx_arr];
			array[idx_arr] = array[idx_min];
			array[idx_min] = aux;
			print_array(array, size);
		}

	}
}
