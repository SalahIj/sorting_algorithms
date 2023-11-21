#include "sort.h"

/**
 * Printing - the function name
 * @arr: input
 * @arrr: input
 * @arra: input
 * @st: input
 * @i: input
 * @j: input
 */
void Printing(int arr[], int *arrr, int *arra, int st, int i, int j)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arrr, i);
	printf("[right]: ");
	print_array(arra, j);
	printf("[Done]: ");
	print_array(&arr[st], i + j);
}

/**
 * merge - the function name
 * @arr: input
 * @tab: input
 * @start: input
 * @middle: input
 * @end: input
 */
void merge(int arr[], int *tab, int start, int middle, int end)
{
	int n_1, n_2, i, j, k, *arr_left, *arr_right;

	n_1 = middle - start + 1;
	n_2 = end - middle;
	arr_left = &tab[0];
	arr_right = &tab[middle + 1];

	for (i = 0; i < n_1; i++)
		arr_left[i] = arr[start + i];
	for (i = 0; i < n_2; i++)
		arr_right[i] = arr[middle + 1 + i];
	for (i = 0, j = 0, k = start; i < n_1 && j < n_2; k++)
	{
		if (arr_left[i] < arr_right[j])
		{
			arr[k] = arr_left[i];
			i++;
		}
		else
		{
			arr[k] = arr_right[j];
			j++;
		}
	}
	for (; i < n_1; i++, k++)
		arr[k] = arr_left[i];
	for (; j < n_2; j++, k++)
		arr[k] = arr_right[j];
	Printing(arr, arr_left, arr_right, start, i, j);
}

/**
 * Merging - the function name
 * @arr: input
 * @tab: input
 * @start: input
 * @end: input
 */
void Merging(int arr[], int *tab, int start, int end)
{
	int middle;

	if (start < end)
	{
		middle = start + (end - start) / 2;
		if ((start + end) % 2 == 0)
			middle--;
		 Merging(arr, tab, start, middle);
		 Merging(arr, tab, middle + 1, end);

		 merge(arr, tab, start, middle, end);
	}
}

/**
 * merge_sort - the function name
 * @array: the input
 * @size: the input
 */
void merge_sort(int *array, size_t size)
{
	int *tab;

	if (array == NULL || size <= 1)
		return;
	tab = malloc(sizeof(int) * size);
	if (tab == NULL)
		exit(EXIT_FAILURE);
	Merging(array, tab, 0, size - 1);
	free(tab);
}
