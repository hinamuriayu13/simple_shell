#include "shell.h"

/**
 * _eputs - Prints an input string.
 * @str: The string to print
 *
 * Return: None.
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Writes the character c to stderr.
 * @c: The char to print
 *
 * Return: On success, 1. On error, -1 is returned, and errno is set
 * appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - Writes the character c to the given file descriptor fdesc.
 * @c: The character to print
 * @fdesc: The file descriptor to write to
 *
 * Return: On success, 1. On error, -1 is returned, and errno
 * is set appropriately.
 */
int _putfd(char c, int fdesc)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fdesc, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Prints an input string to the specified file descriptor fdesc.
 * @str: The string to be printed
 * @fdesc: The file descriptor to write to
 *
 * Return: The number of characters put.
 */
int _putsfd(char *str, int fdesc)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fdesc);
	}
	return (i);
}
