#include "sort.h"

/**
* arra - the function name
* @tab: the first input
* @size: the second input
* Return: the result
*/
int *arra(int *tab, size_t size)
{
size_t max, i, j;
int *arr, c;

max = tab[0];
for (i = 1; i < size; i++)
{
if (tab[i] > (int)max)
max = tab[i];
}
arr = malloc(sizeof(int) * (max + 1));
if (arr == NULL)
exit(EXIT_FAILURE);
for (i = 0; i <= max; i++)
arr[i] = 0;
for (i = 0; i <= max; i++)
{
c = 0;
for (j = 0; j < size; j++)
{
if (tab[j] == (int)i)
c++;
}
arr[i] = c;
}
for (i = 1; i <= max; i++)
arr[i] = arr[i - 1] + arr[i];
print_array(arr, max + 1);
return (arr);
}

/**
* counting_sort - the function name
* @array: the first input
* @size: the second input
*/
void counting_sort(int *array, size_t size)
{
size_t i;
int *arr, *out_arr;

if (array == NULL || size <= 1)
return;
arr = arra(array, size);
out_arr = malloc(sizeof(int) * size);
if (out_arr == NULL)
exit(EXIT_FAILURE);
for (i = size - 1; (int)i >= 0; i--)
{
out_arr[arr[array[i]] - 1] = array[i];
arr[array[i]]--;
}
for (i = 0; i < size; i++)
array[i] = out_arr[i];
free(arr);
free(out_arr);
}
