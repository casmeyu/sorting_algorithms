#include "sort.h"
#include <stdio.h>

/**
 * quick_partition - makes pivot and sorts for quick recursion
 *
 * @array: array to sort
 * @low: start of list
 * @high: end of list
 */
void quick_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot, idx_min, idx_right;
	int aux;

	if (low >= high - 1|| high < 2)
		return;

	pivot = high - 1;
	if (pivot == low)
		return;
	idx_min = low - 1;
	for (idx_right = low; idx_right < high; idx_right++)
	{
		if (array[idx_right] < array[pivot])
		{
			/* swaps */
			idx_min++;
			if (idx_min != idx_right)
			{
				aux = array[idx_right];
				array[idx_right] = array[idx_min];
				array[idx_min] = aux;
				printf("\n***Dentro for***\n");
				print_array(array, size);
			}
		}
	}
	/* swaps the pivot to idx_small + 1
	printf("high - 2: %ld idx_min: %ld\n", high, idx_min);*/
	if (high != idx_min || pivot == idx_min + 1)
	{

		aux = array[idx_min + 1];
		array[idx_min + 1] = array[pivot];
		array[pivot] = aux;
		/* calling recurively */
		printf("\n***Fuera del FOR***\n");
		print_array(array, size);
		/*printf("ISZQUIERA %d to %d\n", array[idx_min + 1], array[pivot - 1]);*/
		quick_partition(array, low, idx_min + 1, size);
		/*printf("DESRECHLEAR %d to %d\n", array[pivot + 1], array[size - 1]);*/
		quick_partition(array, idx_min + 2, size, size);
	}
}
/**
 * quick_sort - sorts an array of integers using quick sort recurisvely
 *
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	quick_partition(array, 0, size, size);
}
