#include "sort.h"

/**
 * Swap_function - the function name
 * @x: the first input
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
 * shell_sort - the function name
 * @array: the first input
 * @size: the second input
*/
void shell_sort(int *array, size_t size)
{
size_t gap, i, j, k;

if (!array || size <= 1)
return;
for (gap = 1; gap < size / 3; gap = (gap * 3) + 1)
;

for (i = gap; i >= 1; i /= 3)
{
for (j = i; j < size; j++)
{
for (k = j; k >= i && array[k] < array[k - i]; k -= i)
Swap_function(&array[k], &array[k - i]);
}
print_array(array, size);
}
}
