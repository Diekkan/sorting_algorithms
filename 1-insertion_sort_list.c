#include "sort.h"
#include <stdio.h>

/**
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL, *aux2 = NULL, *aux0 = NULL;
	int flag;

	if (!list || !*list || !(*list)->next)
		return;
	aux = (*list)->next;
	while(aux)
	{
		flag = 0;
		while (aux->prev && aux->prev->n > aux->n)
		{
			flag = 1;
			aux2 = aux->next;
			aux0 = aux->prev;
			aux->prev->next = aux2;
			aux->next = aux->prev;
			if (aux->next)
				aux->next->prev = aux->prev;
			aux->prev = aux->prev->prev;
			aux->prev->prev->next = aux;
			print_list(*list);
			if (flag == 1)
				break;
		}
		aux = aux->next;
	}
}
