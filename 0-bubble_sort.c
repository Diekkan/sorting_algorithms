#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - Bubble sort algorithm.
 *@array: array to sort
 *@size: elements of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t n = size, i;
	int aux, swap;

	do {
		swap = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				aux  = array[i - 1];
				array[i - 1] = array[i];
				array[i] = aux;
				swap = 1;
				print_array(array, size);
			}
		}
		n = n - 1;
	} while (swap != 0);
}
