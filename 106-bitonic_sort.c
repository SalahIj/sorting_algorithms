#include "sort.h"

/**
 * Bitonic_merge - the function name
 * @tab: input
 * @min: input
 * @cpt: input
 * @dir: input
 */
void Bitonic_merge(int tab[], int min, int cpt, int dir)
{
	int k, i, temp;

	if (cpt > 1)
	{
		k = cpt / 2;
		for (i = min; i < min + k; i++)
		{
			if (dir == (tab[i] > tab[i + k]))
			{
				temp = tab[i];
				tab[i] = tab[i + k];
				tab[i + k] = temp;
			}
		}
		Bitonic_merge(tab, min, k, dir);
		Bitonic_merge(tab, min + k, k, dir);
	}
}

/**
 * Bitonic_sort - the function name
 * @tab: input
 * @min: input
 * @cpt: input
 * @dir: input
 * @size: input
 */
void Bitonic_sort(int tab[], int min, int cpt, int dir, size_t size)
{
	int k;

	if (cpt > 1)
	{
		if (dir >= 1)
		{
			printf("Merging [%d/%ld] (UP):\n", cpt, size);
			print_array(&tab[min], cpt);
		}
		else
		{
			printf("Merging [%d/%ld] (DOWN):\n", cpt, size);
			print_array(&tab[min], cpt);
		}
		k = cpt / 2;
		Bitonic_sort(tab, min, k, 1, size);
		Bitonic_sort(tab, min + k, k, 0, size);
		Bitonic_merge(tab, min, cpt, dir);
		if (dir <= 0)
		{
			printf("Result [%d/%ld] (DOWN):\n", cpt, size);
			print_array(&tab[min], cpt);
		}
		if (dir >= 1)
		{
			printf("Result [%d/%ld] (UP):\n", cpt, size);
			print_array(&tab[min], cpt);
		}
	}
}

/**
 * bitonic_sort - the function name
 * @array: the first input
 * @size: the second input
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	Bitonic_sort(array, 0, (int)size, 1, size);
}
