#include "sort.h"
/**
 * div_and_conquer - takes pivot, finds places and divdes array
 * @array: array pointer
 * @first: first pos element of array
 * @last: last element of array
 * @size: size of array to print it
 * Return: position index of pivot
 */
size_t quick_partition(int *array, size_t low, size_t high, size_t size)
{
	int aux;
	size_t idx_pivot, idx_small, idx_right;

	idx_pivot = high;
	idx_small = low - 1;

	for (idx_right = low; idx_right <= (high - 1); idx_right++)
	{
		if (array[idx_right] < array[idx_pivot])
		{
			idx_small++;
			if (idx_small != idx_right)
			{
				aux = array[idx_small];
				array[idx_small] = array[idx_right];
				array[idx_right] = aux;

				print_array(array, size);
			}
		}
	}
	idx_small++;
	if (array[high] < array[idx_small])
	{
		aux = array[high];
		array[high] = array[idx_small];
		array[idx_small] = aux;

		print_array(array, size);
	}
	return (idx_small);

}

/**
 * quick_recursion - handles the recusive functionality of quick sort
 *
 * @array: pointer to the array to sort and 'cut'
 * @low: start of the sort
 * @high: end of the sort
 * @size: size of the entire array
 */
void quick_recursion(int *array, size_t low, size_t high, size_t size)
{
	size_t idx_pivot;

	if (low < high)
	{
		idx_pivot = quick_partition(array, low, high, size);
		if (idx_pivot > 0)
			quick_recursion(array, low, (idx_pivot - 1), size);
		if (idx_pivot < high)
			quick_recursion(array, (idx_pivot + 1), high, size);
	}
}


/**
 * quick_sort - sort array of integers using quick sort recusively
 *
 * @array: pointer to array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quick_recursion(array, 0, (size - 1), size);
}
