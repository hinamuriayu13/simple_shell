#include "shell.h"

/**
 * _strncpy - Copies a string from source to a destination.
 * @dst: Pointer to the destination string.
 * @sr: Pointer to the source string.
 * @n: The maximum number of characters to be copied. *
 * Return value : A pointer to the destination string.
 */
char *_strncpy(char *dst, char *sr, int n)
{
	int i, j;
	char *s = dst;

	i = 0;
	while (sr[i] != '\0' && i < n - 1)
	{
		dst[i] = sr[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dst[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - Concatenates two strings.
 * @dst: Pointer to the destination string (the first string).
 * @sr: Pointer to the source string (the second string).
 * @n: The maximum number of bytes to be used for concatenation.
 *
 * Return value: A pointer to the concatenated string.
 */
char *_strncat(char *dst, char *sr, int n)
{
	int i, j;
	char *s = dst;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (sr[j] != '\0' && j < n)
	{
		dst[i] = sr[j];
		i++;
		j++;
	}
	if (j < n)
		dst[i] = '\0';
	return (s);
}

/**
 * _strchr - Locates a character in a string.
 * @s: Pointer to the string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the first occurrence of the character in the string, or
 *        NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
