#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the array in question
 * @size: the number of elements in the array that need to be sorted
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
