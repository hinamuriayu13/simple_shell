#include "shell.h"

/**
 * is_cmd - determines if the file is an executable command
 * @inf: the info struct
 * @paths: a path to the file
 *
 * Return: 0 or 1 if true
 */
int is_cmd(info_t *inf, char *paths)
{
	struct stat st;

	(void)inf;
	if (!paths || stat(paths, &st) == -1)
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates the characters
 * @pathsstr: the path string
 * @startindx: the starting index
 * @stopindx: stopping index
 *
 * Return: pointer to a new buffer
 */
char *dup_chars(char *pathsstr, int startindx, int stopindx)
{
	static char buff[1024];
	int a = 0, q = 0;

	for (q = 0, a = startindx; a < stopindx; a++)
		if (pathsstr[a] != ':')
			buff[q++] = pathsstr[a];
	buff[q] = 0;
	return (buff);
}

/**
 * find_path - finds cmd in the path string
 * @inf: the info struct
 * @pathsstr: the path string
 * @cmdf: the cmd to find
 *
 * Return: NULL or full path of cmd if found
 */
char *find_path(info_t *inf, char *pathsstr, char *cmdf)
{
	int a = 0, curt_post = 0;
	char *paths;

	if (!pathsstr)
		return (NULL);
	if ((_strlen(cmdf) > 2) && starts_with(cmdf, "./"))
	{
		if (is_cmd(inf, cmdf))
			return (cmdf);
	}
	while (1)
	{
		if (!pathsstr[a] || pathsstr[a] == ':')
		{
			paths = dup_chars(pathsstr, curt_post, a);
			if (!*paths)
				_strcat(paths, cmdf);
			else
			{
				_strcat(paths, "/");
				_strcat(paths, cmdf);
			}
			if (is_cmd(inf, paths))
				return (paths);
			if (!pathsstr[a])
				break;
			curt_post = a + 1;
		}
		a++;
	}
	return (NULL);
}
