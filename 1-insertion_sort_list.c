#include "sort.h"
/**
 * insertion_sort_list - insertion sort algorithm
 * @list: head position of list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux = *list;
	listint_t *tmp = NULL;

	if (!list || !*list || (*list)->next == NULL)
		return;
	while (aux)
	{
		tmp = aux->next;
		while (tmp && tmp->prev && tmp->n < tmp->prev->n)
		{
			if (tmp->prev != NULL)
				tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;
			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			if (tmp->next != NULL)
				tmp->next->prev = tmp;
			print_list(*list);
		}
		if (!aux->next)
			break;
		if (aux->n < aux->next->n)
			aux = aux->next;
	}
}
