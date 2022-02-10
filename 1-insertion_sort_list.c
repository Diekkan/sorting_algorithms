#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - Insertion sort algorithm.
 *@list: doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *laux = NULL, *aux2 = NULL;
	listint_t *swap1 = NULL, *swap2 = NULL, *swap3 = NULL;

	if (!*list)
		return;
	laux = *list;
	while (laux->next)
	{
		if (laux->n > laux->next->n)
		{
			swap1 = laux, swap2 = laux->next, swap3 = laux->prev;
			if (swap2->next)
			{
				swap1->next->prev = swap1;
			}
			swap1->next = swap2->next;
			swap1->prev = laux->next;
			swap2->prev = swap3;
			swap2->next = swap1;
			swap3->next = swap2;
		}
		printf("1er while: ");
		print_list(*list);
		aux2 = laux;
		while (aux2)
		{
			if (aux2->prev)
				if (aux2->n < aux2->prev->n)
				{
				swap1 = aux2, swap2 = aux2->next, swap3 = aux2->prev;
				if (swap3->prev)
				{
					swap3->prev->next = swap1;
				}
				swap1->prev = swap3->prev;
				swap1->next = swap3;
				swap3->next = swap2;
				swap3->prev = swap1;
				swap2->prev = swap3;
			}
			aux2 = aux2->prev;
		}
		laux = laux->next;
		printf("2ndo while: ");
		print_list(*list);
	}
}
