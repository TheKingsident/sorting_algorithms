#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	int swap_flag;

	if (array == NULL || size < 2)
	{
		return;
	}


	for (i = 0; i < (size - 1); i++)
	{
		swap_flag = 0;

		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
				swap_flag = 1;
			}
		}
		if (swap_flag == 0)
		{
			break;
		}
	}
}
