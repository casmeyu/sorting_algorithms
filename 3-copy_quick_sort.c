#include "sort.h"
#include <stdio.h>

size_t quick_partition(int *array, size_t low, size_t high, size_t size);
void quick_swap(int *x, int *y);
void quick_recursion(int *array, size_t low, size_t high, size_t size);

/**
 * quick_swap - swaps to items in an array
 *
 * @x: poiner to the first item
 * @y: pointer to the second item
 */
void quick_swap(int *x, int *y)
{
	int aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

/**
 * quick_recursion - recursive auxliary function for quick sort
 *
 * @array: array to sort recurively
 * @low: starting point to sort
 * @high: index at which to stop
 * @size: size of the entire array
 */
void quick_recursion(int *array, size_t low, size_t high, size_t size)
{
	size_t idx_pivot;
	
	if (low < high)
	{
		printf("entered if because: %ld < %ld\n", low, high);
		idx_pivot = quick_partition(array, low, high, size);
		printf("idx_pivot: %ld: %d\n", idx_pivot, array[idx_pivot]);
		if (idx_pivot > 0)
			quick_recursion(array, low, (idx_pivot - 1), size);
		if (idx_pivot < high)
			quick_recursion(array, (idx_pivot + 1), high, size);
	}
}

/**
 * quick_partition - recursive functionality for quick sort
 * partitions a list of integers based on the pivot
 *
 * @array: array to sort
 * @low: start of the sort
 * @high: end of the sort
 * @size: size of the entire array
 *
 * Return: the index of the pivot
 */
size_t quick_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t idx_pivot, idx_min, idx_right;

	idx_pivot = high;
	idx_min = low - 1;

	for (idx_right = low; idx_right < high; idx_right++)
	{
		if (array[idx_right] < array[idx_pivot])
		{
			idx_min++;
			if (idx_min != idx_right)
			{
				quick_swap(&array[idx_min], &array[idx_right]);

				print_array(array, size);
			}
		}
	}
	if (array[idx_pivot] < array[idx_min])
	{
		printf("idx_min != pivot (%ld != %ld)\n", idx_min, idx_pivot);
		quick_swap(&array[idx_pivot], &array[idx_min]);

		print_array(array, size);
	}

	return (idx_min + 1);
	
}

/**
 * quick_sort - sorts an array of ints using quick sort
 *
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quick_recursion(array, 0, (size - 1), size);

}
