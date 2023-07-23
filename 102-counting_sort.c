#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array = NULL;
	int *sorted_array = NULL;
	size_t i, max_element = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > max_element)
			max_element = array[i];
	}
	count_array = malloc(sizeof(int) * (max_element + 1));
	if (count_array == NULL)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i <= max_element; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= max_element; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max_element + 1);
	for (i = size - 1; i < size; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(count_array);
	free(sorted_array);
}
