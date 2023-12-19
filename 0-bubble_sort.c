/*
* File_name: 0-bubble_sort.c
* Task_no: 0
* Task_Title: Bubble sort
* Functions: void swap_ints, void bubble_sort
* Created: On December 19, 2023
* Author: Bereket Dereje Mekonnen
* GitHub repository: sorting_algorithms
* Project Title: 0x1B. C - Sorting algorithms & Big O
* Directory: sorting_algorithms
*/

#include "sort.h"

/**
 * swap_ints - It Swap two integers in an array.
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
 * bubble_sort - It Sort an array of integers
 *               in ascending order.
 *
 * Author: Bereket Dereje Mekonnen.
 *
 * @array: An array of integers to sort.
 *
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
