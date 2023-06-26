#include "shell.h"

/**
 * _myenv - Prints the current environment.
 * @inf: a pointer to a structure (presumably containing information
 *          about the shell)
 * Return value: Always 0.
 */	
int _myenv(info_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @inf: a pointer to a structure (presumably containing information
 *      about the shell)
 * @name: env variable name
 *
 * Return value: The value of the environment variable.
 */
char *_getenv(info_t *inf, const char *name)
{
	list_t *node = inf->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initializes a new environment variable or modifies an existing
 *             one.
 * @inf: a pointer to a structure (presumably containing information
 *        about the shell)
 *  Return value: Always 0.
 */
int _mysetenv(info_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Removes an environment variable.
 * @inf: a pointer to a structure (presumably containing information
 *        about the shell)
 * Return value: Always 0.
 */
int _myunsetenv(info_t *inf)
{
	int i;

	if (inf->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= inf->argc; i++)
		_unsetenv(inf, inf->argv[i]);

	return (0);
}

/**
 * populate_env_list - Populates the environment linked list.
 * @inf: a pointer to a structure (presumably containing information
 *          about the shell)
 * Return value: Always 0.
 */
int populate_env_list(info_t *inf)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	inf->env = node;
	return (0);
}
