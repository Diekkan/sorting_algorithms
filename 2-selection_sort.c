#include "sort.h"

/**
 * selection_sort - Selection sort algorithm.
 *@array: array to be sorted
 *@size: no of elements in array.
 */
void selection_sort(int *array, size_t size)
{
	int minvalue = 0, tmp = 0, flag;
	size_t i, j;

	for (j = 0; j < size - 1; j++)
	{
		flag = 0;
		for (i = j; i < size - 1; i++)
		{
			if (flag == 0)
			{
				if (array[i] < array[i + 1])
				{
					flag = 1, minvalue = array[i];
					tmp = i;
				}
				if (array[i] > array[i + 1])
				{
					flag = 1, minvalue = array[i + 1];
					tmp = i + 1;
				}
			}
			if (flag == 1)
			{
				if (minvalue < array[i + 1])
				{
				}
				if (minvalue > array[i + 1])
				{
					flag = 1, minvalue = array[i + 1];
					tmp = i + 1;
				}
			}
		}
		array[tmp] = array[j];
		array[j] = minvalue;
		print_array(array, size);
	}
}
