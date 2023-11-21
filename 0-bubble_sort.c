#include "sort.h"

/**
 *  * Swap_function - the function name
 *   * @x: the first input
 *    * @y: the second input
 */
void Swap_function(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 *  * bubble_sort - the function name
 *   * @array: the first input
 *    * @size: the second input
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temoin;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		temoin = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap_function(&array[j], &array[j + 1]);
				print_array(array, size);
				temoin = 1;
			}
		}
		if (temoin == 0)
			break;
	}
}
