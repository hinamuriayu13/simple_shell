#include "shell.h"

/**
 * add_node - add nodes from thr strat of the list
 * @heed: title of pointer to the head node
 * @str: str field of node
 * @numb: node index used by history
 *
 * Return: the size of the list
 */
list_t *add_node(list_t **heed, const char *str, int numb)
{
	list_t *new_heed;

	if (!heed)
		return (NULL);
	new_heed = malloc(sizeof(list_t));
	if (!new_heed)
		return (NULL);
	_memset((void *)new_heed, 0, sizeof(list_t));
	new_heed->numb = numb;
	if (str)
	{
		new_heed->str = _strdup(str);
		if (!new_heed->str)
		{
			free(new_heed);
			return (NULL);
		}
	}
	new_heed->next = *heed;
	*heed = new_heed;
	return (new_heed);
}

/**
 * add_node_end - add nodes to the end of the list
 * @heed: title pointer to the head node
 * @str: str field of node
 * @numb: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **heed, const char *str, int numb)
{
	list_t *current_nodes, *nodes;

	if (!heed)
		return (NULL);

	nodes = *heed;
	current_nodes = malloc(sizeof(list_t));
	if (!current_nodes)
		return (NULL);
	_memset((void *)current_nodes, 0, sizeof(list_t));
	current_nodes->numb = numb;
	if (str)
	{
		current_nodes->str = _strdup(str);
		if (!current_nodes->str)
		{
			free(current_nodes);
			return (NULL);
		}
	}
	if (nodes)
	{
		while (nodes->next)
			nodes = nodes->next;
		node->next = current_nodes;
	}
	else
		*heed = current_nodes;
	return (current_nodes);
}

/**
 * print_list_str - prints the str statement of a list
 * @b: pointer of the first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *b)
{
	size_t a = 0;

	while (b)
	{
		_puts(b->str ? b->str : "(nil)");
		_puts("\n");
		b = b->next;
		a++;
	}
	return (a);
}

/**
 * delete_node_at_index - deletes the nodes given index
 * @heed: title of pointer to first node
 * @indx: index of node to delete
 *
 * Return: on success 1, on failure 0
 */
int delete_node_at_index(list_t **heed, unsigned int indx)
{
	list_t *nodes, *bef_nodes;
	unsigned int a = 0;

	if (!heed || !*heed)
		return (0);

	if (!indx)
	{
		nodes = *heed;
		*heed = (*heed)->next;
		free(nodes->str);
		free(nodes);
		return (1);
	}
	nodes = *heed;
	while (nodes)
	{
		if (a == indx)
		{
			bef_nodes->next = nodes->next;
			free(nodes->str);
			free(nodes);
			return (1);
		}
		a++;
		bef_nodes = nodes;
		nodes = nodes->next;
	}
	return (0);
}

/**
 * free_list - frees all the nodes in the list
 * @head_ptr: addresses pointer of head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *nodes, *nextt_nodes, *heed;

	if (!head_ptr || !*head_ptr)
		return;
	heed = *head_ptr;
	nodes = heed;
	while (nodes)
	{
		nextt_nodes = nodes->next;
		free(nodes->str);
		nodes = nextt_nodes;
	}
	*head_ptr = NULL;
}
