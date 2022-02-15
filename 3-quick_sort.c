#include "sort.h"
/**
 * quick_sort - function that sorts an array of integers in,
 * ascending order using the Quick sort algorithm.
 * @array: the array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	QuickSort(array, 0, size - 1, size);
}
/**
 * QuickSort - quick sort
 * @array: the array
 * @pos_ini: first position of the array
 * @pos_fin: last position of the array
 * @size: size of arr
 */
void QuickSort(int *array, int pos_ini, int pos_fin, size_t size)
{
	int pivot = pos_fin, j = pos_ini, i = pos_ini - 1, aux;

	if (pos_ini == pos_fin)
		return;
	for (; j < pos_fin; j++)
	{
		if (array[j] < array[pivot])
		{
			i++;
			if (array[j] < array[i])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[pivot])
	{
		aux = array[i + 1];
		array[i + 1] = array[pivot];
		array[pivot] = aux;
		print_array(array, size);
	}
	if (pos_ini <= i)
		QuickSort(array, pos_ini, i, size);
	if (i + 1 <= pos_fin)
		QuickSort(array, i + 1, pos_fin, size);
}
