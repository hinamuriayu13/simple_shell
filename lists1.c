#include "shell.h"

/**
 * list_len - deciding the length of a linked list
 * @b: pointer of the first node
 *
 * Return: size of the list
 */
size_t list_len(const list_t *b)
{
	size_t a = 0;

	while (b)
	{
		b = b->next;
		a++;
	}
	return (a);
}

/**
 * list_to_strings - returns the array strings of the list->str
 * @heed: head pointer of the first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *heed)
{
	list_t *nodes = heed;
	size_t a = list_len(heed), q;
	char **strx;
	char *str;

	if (!heed || !a)
		return (NULL);
	strx = malloc(sizeof(char *) * (a + 1));
	if (!strx)
		return (NULL);
	for (a = 0; nodes; nodes = nodes->next, a++)
	{
		str = malloc(_strlen(nodes->str) + 1);
		if (!str)
		{
			for (q = 0; q < a; q++)
				free(strx[q]);
			free(strx);
			return (NULL);
		}
		str = _strcpy(str, nodes->str);
		strx[a] = str;
	}
	strx[a] = NULL;
	return (strx);
}

/**
 * print_list - prints all the elements of list_t linked
 * @b: pointer of the fist node
 *
 * Return: size of the list
 */
size_t print_list(const list_t *b)
{
	size_t a = 0;

	while (b)
	{
		_puts(convert_number(b->numb, 10, 0));
		_putchar(':');
		_putchar('');
		_puts(b->str ? b->str : "(nil)");
		_puts("\n");
		b = b->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - withdraws the nodes whose strings start with prefix
 * @nodes: pointer of the head list
 * @prefixs: the strings match
 * @d: the next character after prefix
 *
 * Return: null or match node
 */
list_t *node_starts_with(list_t *nodes, char *prefixs, char d)
{
	char *f = NULL;

	while (node)
	{
		f = starts_with(nodes->str, prefixs);
		if (f && ((d == -1) || (*f == d)))
			return (nodes);
		nodes = nodes->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of the nodes
 * @heed: pointer to the list head
 * @nodes: pointer to the node
 *
 * Return: -1 or index of the node
 */
ssize_t get_node_index(list_t *heed, list_t *nodes)
{
	size_t a = 0;

	while (heed)
	{
		if (heed == nodes)
			return (a);
		heed = heed->next;
		a++;
	}
	return (-1);
}
