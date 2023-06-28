#include "shell.h"

/**
 * get_history_file - gets the files history
 * @inf: parameter of the struct
 *
 * Return: the string allocated containg the history file
 */

char *get_history_file(info_t *inf)
{
	char *buff, *direct;

	direct = _getenv(inf, "HOME=");
	if (!direct)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(direct) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, direct);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return  (buff);
}

/**
 * write_history - creates files, or adjoin to an existing file
 * @inf: the parameter of the struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_t *inf)
{
	ssize_t fdesc;
	char *filename = get_history_file(inf);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fdesc = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fdesc == -1)
		return (-1);
	for (node = inf->history; node; node = node->next)
	{
		_putsfd(node->str, fdesc);
		_putfd('\n', fdesc);
	}
	_putfd(BUF_FLUSH, fdesc);
	close(fdesc);
	return (1);
}

/**
 * read_history - reads the history from the file
 * @inf: the parameter of the struct
 *
 * Return: histcount on success, otherwise 0
 */
int read_history(info_t *inf)
{
	int a, lastt = 0, lineco = 0;
	ssize_t fdesc, rdle, tsize = 0;
	struct stat st;
	char *buff = NULL, *filename = get_history_file(inf);

	if (!filename)
		return (0);

	fdesc = open(filename, O_RDONLY);
	free(filename);
	if (fdesc == -1)
		return (0);
	if (!fstat(fdesc, &st))
		tsize = st.st_size;
	if (tsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (tsize + 1));
	if (!buff)
		return (0);
	rdle = read(fdesc, buff, tsize);
	buff[tsize] = 0;
	if (rdle <= 0)
		return (free(buff), 0);
	close(fdesc);
	for (a = 0; a < tsize; a++)
		if (buff[a] == '\n')
		{
			buff[a] = 0;
			build_history_list(inf, buff + lastt, lineco++);
			lastt = a + 1;
		}
	if (lastt != a)
		build_history_list(inf, buff + lastt, lineco++);
	free(buff);
	inf->histcount = lineco;
	while (inf->histcount-- >= HIST_MAX)
		delete_node_at_index(&(inf->history), 0);
	renumber_history(inf);
	return (inf->histcount);
}

/**
 * build_history_list - it adds entry to an already history linked list
 * @inf: the structure holding potential arguments
 * @buff: the buffer between
 * @lineco: the history linecount or histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *inf, char *buff, int lineco)
{
	list_t *node = NULL;

	if (inf->history)
		node = inf->history;
	add_node_end(&node, buff, lineco);

	if (!inf->history)
		inf->history = node;
	return (0);
}
/**
 * renumber_history - renumbers the history linked lists after change been made
 * @inf: the structure holding potential arguments
 *
 * Return: the new histcount
 */
int renumber_history(info_t *inf)
{
	list_t *node = inf->history;
	int a = 0;

	while (node)
	{
		node->num = a++;
		node = node->next;
	}
	return (inf->histcount = a);
}
