#include "sort.h"

/**
 * Swap_function - the function name
 * @x: the fisrtt input
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
 * selection_sort - the function name
 * @array: the first input
 * @size: the second input
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, indice;

	if (array == NULL || size < 2)
		return;
	while (i < size - 1)
	{
		indice = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[indice])
				indice = j;
		}
		if (indice != i)
		{
			Swap_function(&array[i], &array[indice]);
			print_array(array, size);
		}
		i++;
	}
}
