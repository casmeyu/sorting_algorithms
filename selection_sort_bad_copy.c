#include "sort.h"
#include <stdio.h>
/**
 * check_min - Returns the index number in an array of integers
 *
 * @array: array of integers
 *
 * Return: index
 */
size_t check_min(int *array, size_t idx)
{
	size_t min_idx;
	int min;

	(void) min_idx;
	printf("array 0: %d\n", array[0]);
	min = array[idx];
	for (; array[idx]; idx++)
	{
		if (array[idx] < min)
			min_idx = idx;
	}

	return min_idx;
	
}

/**
 * selection_sort - sorts an array of inteers using selection sort.
 * Good memory, bad performance...
 *
 * @array: array of integers to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t idx_arr, idx_min;
	int aux;

	printf("wtf");
	(void)size;
	(void)aux;
	(void)idx_min;
	printf("oey mate... hwats going on\n");
	for (idx_arr = 0; array[idx_arr]; idx_arr++)
	{
		printf("calling check_min\n");
		check_min(&array[idx_arr], idx_arr);
	}
}
