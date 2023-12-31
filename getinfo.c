#include "shell.h"

/**
 * clear_info - Initializes the info_t struct by clearing its fields.
 * @inf: Address of the info_t struct.
 *
 * Description: Clears the fields of the info_t struct.
 */
void clear_info(info_t *inf)
{
	inf->arg = NULL;
	inf->argv = NULL;
	inf->path = NULL;
	inf->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @inf: struct address
 * @av: argument vector
 *
 * Description: Initializes the info_t struct by setting its fields based on the arguments.
 */
void set_info(info_t *inf, char **av)
{
	int i = 0;

	inf->fname = av[0];
	if (inf->arg)
	{
		inf->argv = strtow(inf->arg, " \t");
		if (!inf->argv)
		{
			inf->argv = malloc(sizeof(char *) * 2);
			if (inf->argv)
			{
				inf->argv[0] = _strdup(inf->arg);
				inf->argv[1] = NULL;
			}
		}
		for (i = 0; inf->argv && inf->argv[i]; i++)
			;
		inf->argc = i;

		replace_alias(inf);
		replace_vars(inf);
	}
}

/**
 * free_info - frees info_t struct fields
 * @inf: Address of the info_t struct.
 * @all: Flag indicating whether to free all fields.
 *
 * Description: Frees the allocated memory of the info_t struct fields.
 */
void free_info(info_t *inf, int all)
{
	ffree(inf->argv);
	inf->argv = NULL;
	inf->path = NULL;
	if (all)
	{
		if (!inf->cmd_buf)
			free(inf->arg);
		if (inf->env)
			free_list(&(inf->env));
		if (inf->history)
			free_list(&(inf->history));
		if (inf->alias)
			free_list(&(inf->alias));
		ffree(inf->environ);
		inf->environ = NULL;
		bfree((void **)inf->cmd_buf);
		if (inf->readfd > 2)
			close(inf->readfd);
		_putchar(BUF_FLUSH);
	}
}
