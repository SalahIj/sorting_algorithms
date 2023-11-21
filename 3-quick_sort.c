#include "sort.h"

/**
 * Swap_function - the function name
 * @x: the fisrt input
 * @y: the second input
*/
void Swap_function(int *x, int *y)
{
int tmp;

tmp = *x;
*x = *y;
*y = tmp;
}

/**
 * Partition_function - the function name
 * @tab: the first input
 * @first: the second input
 * @last: the third input
 * @size: the fourth input
 * Return: the result
*/
int Partition_function(int *tab, ssize_t first, ssize_t last, size_t size)
{
int pivot = tab[last];
ssize_t i = first, j = first;

while (j < last)
{
if (tab[j] < pivot)
{
if (tab[i] != tab[j])
{
Swap_function(&tab[i], &tab[j]);
print_array(tab, size);
}
i++;
}
j++;
}
if (tab[i] != tab[last])
{
Swap_function(&tab[i], &tab[last]);
print_array(tab, size);
}
return ((int)i);
}

/**
 * Quick_sort - the function name
 * @tab: the first input
 * @first: the second input
 * @last: the third input
 * @size: the fourth input
*/
void Quick_sort(int *tab, ssize_t first, ssize_t last, int size)
{
ssize_t indice;


if (first < last)
{
indice = Partition_function(tab, first, last, size);

Quick_sort(tab, first, indice - 1, size);
Quick_sort(tab, indice + 1, last, size);
}
}

/**
 * quick_sort - the function name
 * @array: the fisrt input
 * @size: the second input
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size <= 1)
return;
Quick_sort(array, 0, size - 1, size);
}
