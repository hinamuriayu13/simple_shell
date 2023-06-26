#include "shell.h"

/**
 * bfree - frees all pointer and NULLs the address
 * @ptrol: adresses the pointer to be free
 *
 * Return: 0, or 1 if freed
 */
int bfree(void **ptrol)
{
	if (ptrol && *ptrol)
	{
		free(*ptrol);
		*ptrol = NULL;
		return (1);
	}
	return (0);
}
