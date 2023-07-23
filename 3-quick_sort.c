#include "sort.h"

/**
 * swap - Swap two integers
 * @a: the first number
 * @b: the second number
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - partition scheme for quick sort
 * @array: the array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * Return: Index of the pivot element
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

/**
 * quick_sort_helper - Recursive function to perform the Quick sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: size of the array
 */

void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi, i;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quicksort(array, 0, (int)size - 1);
}
