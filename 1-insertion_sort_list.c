#include "sort.h"
/**
 * insertion_sort_list - Insertion sort algorithm
 * @list: header ptr
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *tmp = NULL, *aux = NULL;

	if (!list || !(*list))
	return;

	if ((*list)->next)
	{
		head = (*list)->next;
		tmp = head->prev;
	}

	while (tmp)
	{
		if (head == NULL)
		tmp = tmp->next;
		else
		tmp = head->prev;

		while (tmp && tmp->prev && tmp->n < tmp->prev->n)
		{
			if (tmp->next)
				tmp->next->prev = tmp->prev;

			if (tmp->prev->prev)
				tmp->prev->prev->next = tmp;
			aux = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev->next = aux;
			aux = tmp->prev->prev;
			tmp->prev->prev = tmp;
			tmp->prev = aux;

			if ((*list)->prev)
				*list = (*list)->prev;
			print_list(*list);
		}
		if (head)
			head = head->next;
	}
}
