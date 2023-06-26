#include "shell.h"

/**
 * _memset - fills the memory with a constant byte
 * @q: the pointer to the memory area
 * @x: the byte to fill *q with
 * @p: the amount of byte to be filled
 * Return: (q) a pointer to the memory area q
 */
char *_memset(char *q, char x, unsigned int p)
{
	unsigned int a;

	for (a = 0; a < p; a++)
		q[a] = x;
	return (q);
}

/**
 * ffree - `frees a string to strings
 * @pps: string of strings
 */
void ffree(char **pps)
{
	char **x = pps;

	if (!pps)
		return;
	while (*pps)
		free(*pps++);
	free(x);
}

/**
 * _realloc - relocates a block of memory
 * @ptrs: pointers to previous malloc block
 * @prev_sizes: bytes sizes of old blocks
 * @new_sizes: bytes sizes of new blocks
 *
 * Return: pointer to block name
 */
void *_realloc(void *ptrs, unsigned int prev_sizes, unsigned int new_sizes)
{
	char *x;

	if (!ptrs)
		return (malloc(new_sizes));
	if (!new_sizes)
		return (free(ptrs), NULL);
	if (new_sizes == prev_sizes)
		return (ptrs);
	x = malloc(new_sizes);
	if (!x)
		return (NULL);
	prev_sizes = prev_sizes < new_sizes ? prev_sizes : new_sizes;
	while (prev_sizes--)
		x[prev_sizes] = ((char *)ptrs)[prev_sizes];
	free(ptr);
	return (p);
}
