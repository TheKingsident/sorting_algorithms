#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	helper(array, 0, size - 1, size);

}

/**
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: The lower bound of the partition.
 * @high: The upper bound of the partition.
 * @size: The size of the array.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] > pivot)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * helper - Implements the quick sort algorithm through recursion.
 * @array: The array to be sorted.
 * @low: The lower bound of the partition to be sorted.
 * @high: The upper bound of the partition to be sorted.
 * @size: The size of the array.
 */
void helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		helper(array, low, pi - 1, size);
		helper(array, pi + 1, high, size);
	}
}

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
