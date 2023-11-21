#include "sort.h"

/**
 *  * Swap_function - the function name
 *   * @Node: the first input
 *    * @data: the second input
 *     * Return: the result
 */
listint_t *Swap_function(listint_t *Node, listint_t **data)
{
	listint_t *node_1, *node_2;

	node_1 = Node->prev;
	node_2 = Node;

	node_1->next = node_2->next;
	if (node_2->next)
		node_2->next->prev = node_1;
	node_2->next = node_1;
	node_2->prev = node_1->prev;
	node_1->prev = node_2;
	if (node_2->prev)
		node_2->prev->next = node_2;
	else
		*data = node_2;
	return (node_2);
}

/**
 *  * insertion_sort_list - the function name
 *   * @list: the input of the function
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *noeud;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	noeud = (*list)->next;
	for (; noeud; noeud = noeud->next)
	{
		while ((noeud->prev) && (noeud->prev->n > noeud->n))
		{
			noeud = Swap_function(noeud, list);
			print_list(*list);
		}
	}
}
