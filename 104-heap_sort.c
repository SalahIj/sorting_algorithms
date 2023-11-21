#include "sort.h"

/**
 * Swap_function - the functio name
 * @x: the fisrt input
 * @y: the second input
 */
void Swap_function(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * Heapify - the function name
 * @tab: the input
 * @n: the input
 * @size: the input
 * @i: the input
 */
void Heapify(int tab[], size_t n, size_t size, int i)
{
	int left, right, max;

	max = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (right < (int)n && tab[right] > tab[max])
		max = right;
	if (left < (int)n && tab[left] > tab[max])
		max = left;

	if (max != i)
	{
		Swap_function(&tab[i], &tab[max]);
		print_array(tab, size);
		Heapify(tab, n, size, max);
	}
}

/**
 * heap_sort - the function name
 * @array: the first input
 * @size: the second input
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size <= 1)
		return;

	i = (size / 2) - 1;
	while ((int)i >= 0)
	{
		Heapify(array, size, size, i);
		i--;
	}
	for (i = size - 1; i > 0; i--)
	{
		Swap_function(&array[0], &array[i]);
		print_array(array, size);
		Heapify(array, i, size, 0);
	}
}
