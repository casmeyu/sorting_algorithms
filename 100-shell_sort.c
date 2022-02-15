#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array of integers using shell sort and Knuth's formula
 *
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t idx, idx_g, gap = 1;
	int aux;

	if (!array || size < 2)
		return;

	/* calculate Knuth's gap */
	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (idx = gap; idx < size; idx++)
		{
			aux = array[idx];
			idx_g = idx;
			while (idx_g >= gap && array[idx_g - gap] > aux)
			{
				array[idx_g] = array[idx_g - gap];
				idx_g -= gap;
			}

			array[idx_g] = aux;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
