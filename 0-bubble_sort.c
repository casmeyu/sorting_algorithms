#include "sort.h"
#include <stdio.h>
/**
 * bubble_sort - sorts a list in ascending order using the
 * bubble sort algorithm
 *
 * @array: an array of integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int aux, end = 0;

	printf("size: %ld\n", size);

	while (end == 0)
	{
		end = 1;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				end = 0;
				aux = array[i];
				array[i] = array[i - 1];
				array[i - 1] = aux;
				print_array(array, size);
			}
		}
	}
}
