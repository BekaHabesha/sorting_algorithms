/*
* File_name: 107-quick_sort_hoare.c
* Task_no: 11
* Task_Title: 11.Quick Sort
*           - Hoare Partition scheme
* Functions: void quick_sort_hoare, void swap_ints,
*            void hoare_sort, int hoare_partition.
* Created: On December 19, 2023
* Author: Bereket Dereje Mekonnen
* GitHub repository: sorting_algorithms
* Project Title: 0x1B. C - Sorting algorithms & Big O
* Directory: sorting_algorithms
*/

#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - It Swaps two integers in an array.
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
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
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
 *
 * Description: Uses the last element of the partition as the pivot.
 *              It Prints the array after each swap of two elements.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}


/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 *
 * Author: Bereket Dereje Mekonnen.
 *
 * @array: An array of integers to sort.
 *
 * @size: The size of the array.
 *
 * @left: The starting index of the array partition to order.
 *
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}


/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 *
 * Author: Bereket Dereje Mekonnen.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. It Prints
 *              the array after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
