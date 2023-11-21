#include "sort.h"

/**
 * Swap_function - the function name
 * @head: the first input
 * @node1: the second input
 * @node2: the third input
*/
void Swap_function(listint_t **head, listint_t *node1, listint_t *node2)
{
listint_t *NODE1, *NODE2;

NODE1 = node1->prev;
NODE2 = node2->next;

if (NODE1 != NULL)
NODE1->next = node2;
else
*head = node2;
node1->prev = node2;
node1->next = NODE2;
node2->prev = NODE1;
node2->next = node1;
if (NODE2 != NULL)
NODE2->prev = node1;
}

/**
 * cocktail_sort_list - the function name
 * @list: the input of the function
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *node;
int indice = 1;

if (!list || !*list || !(*list)->next)
return;
while (indice != 0)
{
for (node = *list; node->next != NULL; node = node->next)
{
if (node->n > node->next->n)
{
Swap_function(list, node, node->next);
print_list(*list);
node = node->prev;
indice++;
}
}
if (indice == 0)
break;
indice = 0;
while (node->prev)
{
if (node->n < node->prev->n)
{
Swap_function(list, node->prev, node);
print_list(*list);
node = node->next;
indice++;
}
node = node->prev;
}
}
}
