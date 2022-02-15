#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * counting_sort - sorts an array of integers using counting sort
 *
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t idx, max;
	int *keys, *final;

	if (!array || size < 2)
		return;

	max = array[0];
	for (idx = 0; idx < size; idx++)
		if ((int)max < array[idx])
			max = array[idx] + 1;

	keys = malloc((max) * sizeof(*keys));
	if (!keys)
		return;

	for (idx = 0; idx < size; idx++)
		keys[array[idx]] += 1;

	/* modify keys by adding previous ones */
	for (idx = 1; idx < max; idx++)
		keys[idx] += keys[idx - 1];

	print_array(keys, max);

	final = malloc(size * sizeof(*final));
	if (!final)
		return;

	for (idx = 0; idx < size; idx++)
		if (keys[array[idx]] > 0)
			final[keys[array[idx]] - 1] = array[idx];

	for (idx = 0; idx < size; idx++)
		array[idx] = final[idx];
}
