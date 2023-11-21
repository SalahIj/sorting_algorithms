#include "sort.h"

/**
 * Get_max - the function name
 * @tab: the first input
 * @n: the second input
 * Return: the result
 */
int Get_max(int tab[], size_t n)
{
	size_t i = 1;
	int m;

	m = tab[0];
	while (i < n)
	{
		if (m < tab[i])
			m = tab[i];
		i++;
	}
	return (m);
}

/**
 * Counting_sort - the function name
 * @tab: the input
 * @n: the input
 * @div: the input
 */
void Counting_sort(int tab[], size_t n, int div)
{
	int *arr, *out_arr;
	size_t i;

	arr = malloc(sizeof(int) * 10);
	if (arr == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; i < 10; i++)
		arr[i] = 0;
	for (i = 0; i < n; i++)
		arr[(tab[i] / div) % 10]++;
	for (i = 1; i < 10; i++)
		arr[i] = arr[i] + arr[i - 1];
	out_arr = malloc(sizeof(int) * n);
	if (out_arr == NULL)
		exit(EXIT_FAILURE);
	for (i = n - 1; i != SIZE_MAX; i--)
	{
		out_arr[arr[(tab[i] / div) % 10] - 1] = tab[i];
		arr[(tab[i] / div) % 10]--;
	}
	for (i = 0; i < n; i++)
		tab[i] = out_arr[i];
	free(arr);
	free(out_arr);
}

/**
 * radix_sort - the function name
 * @array: the input
 * @size: the input
 */
void radix_sort(int *array, size_t size)
{
	int max, i;

	if (array == NULL || size <= 1)
		return;
	max = Get_max(array, size);
	for (i = 1; max / i > 0; i *= 10)
	{
		Counting_sort(array, size, i);
		print_array(array, size);
	}
}
