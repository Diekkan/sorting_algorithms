#include "sort.h"
/**
 * selection_sort - sorts an array in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = -1, pos;
	int aux, min, flag = 0;

	if (!array || size <= 1)
		return;
	for (j = j + 1; j < size; j++)
	{
		flag = 0;
		min = array[j];
		for (i = i + 1; i < size; i++)
		{
			if (array[i] < min)
			{
				min = array[i];
				pos = i;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			aux = array[pos];
			array[pos] = array[j];
			array[j] = aux;
			print_array(array, size);
		}
		i = j;
	}
}
