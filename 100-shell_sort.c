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
	size_t idx, gap = 1;
	int aux, flag = 1;

	if (size < 2)
		return;

	(void) array;
	/* calculate Knuth's gap */
	while (gap < size)
		gap = (gap * 3) + 1;

	if ((gap / 3) >= 1)
		gap /= 3;

	while (flag == 1)
	{
		flag = 0;
		for (idx = gap; idx < size; idx++)
		{
			if (array[idx - gap] > array[idx])
			{
				aux = array[idx];
				array[idx] = array[idx - gap];
				array[idx - gap] = aux;
				flag = 1;
			}
		}

		if ((gap / 3) >= 1)
		{
			gap /= 3;
			print_array(array, size);
		}
	}
	print_array(array, size);
}
