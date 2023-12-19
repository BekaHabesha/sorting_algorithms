/*
* File_name: 3-quick_sort.c
* Task_no: 3
* Task_Title: 3.Quick sort
* Functions: void quick_sort, void swap_ints,
*            void lomuto_sort, int lomuto_partition.
* Created: On December 19, 2023
* Author: Bereket Dereje Mekonnen
* GitHub repository: sorting_algorithms
* Project Title: 0x1B. C - Sorting algorithms & Big O
* Directory: sorting_algorithms
*/

#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 *
 * Author: Bereket Dereje Mekonnen.
 *
 * @a: The first integer to swap.
 *
 * @b: The second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * lomuto_partition - Order a subset of an array of integers
 *                    according to the lomuto partition
 *                    scheme (last element as pivot).
 *
 * Author: Bereket Dereje Mekonnen.
 *
 * @array: The array of integers.
 *
 * @size: The size of the array.
 *
 * @left: The starting index of the subset to order.
 *
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}


/**
 * lomuto_sort - It Implement the quicksort
 *               algorithm through recursion.
 *
 * @array: An array of integers to sort.
 *
 * @size: The size of the array.
 *
 * @left: The starting index of the array
 *        partition to order.
 *
 * @right: The ending index of the array
 *         partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}


/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 *
 * Author: Bereket Dereje Mekonnen.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 *              It Prints the array after each swap
 *              of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
