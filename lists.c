#include "shell.h"

/**
 * add_node - add nodes from the start of the list
 * @hd: pointer to the head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: the size of the list
 */
list_t *add_node(list_t **hd, const char *str, int num)
{
	list_t *new_node;

	if (!hd)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->next = *hd;
	*hd = new_node;
	return (new_node);
}

/**
 * add_node_end - add nodes to the end of the list
 * @hd: pointer to the head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **hd, const char *str, int num)
{
	list_t *current_node, *node;

	if (!hd)
		return (NULL);

	node = *hd;
	current_node = malloc(sizeof(list_t));
	if (!current_node)
		return (NULL);
	_memset((void *)current_node, 0, sizeof(list_t));
	current_node->num = num;
	if (str)
	{
		current_node->str = _strdup(str);
		if (!current_node->str)
		{
			free(current_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = current_node;
	}
	else
		*hd = current_node;
	return (current_node);
}

/**
 * print_list_str - prints the str statement of a list
 * @hd: pointer to the first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *hd)
{
	size_t size = 0;

	while (hd)
	{
		_puts(hd->str ? hd->str : "(nil)");
		_puts("\n");
		hd = hd->next;
		size++;
	}
	return (size);
}

/**
 * delete_node_at_index - deletes the nodes given index
 * @hd: pointer to the first node
 * @index: index of node to delete
 *
 * Return: on success 1, on failure 0
 */
int delete_node_at_index(list_t **hd, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!hd || !*hd)
		return (0);

	if (index == 0)
	{
		node = *hd;
		*hd = (*hd)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *hd;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all the nodes in the list
 * @hd_ptr: pointer to the head node
 *
 * Return: void
 */
void free_list(list_t **hd_ptr)
{
	list_t *node, *next_node, *hd;

	if (!hd_ptr || !*hd_ptr)
		return;
	hd = *hd_ptr;
	node = hd;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*hd_ptr = NULL;
}
