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
 * ffree - frees a string of strings
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
 * _realloc - reallocates a block of memory
 * @ptr: pointer to the previous malloc block
 * @prev_size: byte size of the old block
 * @new_size: byte size of the new block
 *
 * Return: pointer to the new block
 */
void *_realloc(void *ptr, unsigned int prev_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == prev_size)
		return (ptr);
	p = malloc(new_size);
	if (!p)
		return (NULL);
	prev_size = prev_size < new_size ? prev_size : new_size;
	while (prev_size--)
		p[prev_size] = ((char *)ptr)[prev_size];
	free(ptr);
	return (p);
}
