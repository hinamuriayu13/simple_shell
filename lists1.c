#include "shell.h"

/**
 * list_len - determining the length of a linked list
 * @b: pointer to the first node
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
 * list_to_strings - returns the array of strings from the list->str
 * @hd: head pointer to the first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *hd)
{
	list_t *nodes = hd;
	size_t a = list_len(hd), q;
	char **strx;
	char *str;

	if (!hd || !a)
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
 * print_list - prints all the elements of list_t linked list
 * @hd: pointer to the first node
 *
 * Return: size of the list
 */
size_t print_list(const list_t *hd)
{
	size_t a = 0;

	while (hd)
	{
		_puts(convert_number(hd->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hd->str ? hd->str : "(nil)");
		_puts("\n");
		hd = hd->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - retrieves the nodes whose strings start with prefix
 * @nodes: pointer to the head list
 * @prefix: the prefix to match
 * @d: the next character after prefix
 *
 * Return: matching node or NULL
 */
list_t *node_starts_with(list_t *nodes, char *prefix, char d)
{
	char *f = NULL;

	while (nodes)
	{
		f = starts_with(nodes->str, prefix);
		if (f && ((d == -1) || (*f == d)))
			return (nodes);
		nodes = nodes->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of the node
 * @hd: pointer to the list head
 * @nodes: pointer to the node
 *
 * Return: -1 or index of the node
 */
ssize_t get_node_index(list_t *hd, list_t *nodes)
{
	size_t a = 0;

	while (hd)
	{
		if (hd == nodes)
			return (a);
		hd = hd->next;
		a++;
	}
	return (-1);
}
