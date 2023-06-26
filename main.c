#include "shell.h"

/**
 * main - the entry point
 * @agc: the arg count
 * @agv: the arg vector
 *
 * Return: 1 on error, 0 on sucess
 */
int main(int agc, char **agv)
{
	info_t inf[] = {INFO_INIT};
	int fdesc = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fdesc)
			: "r" (fdesc));
	if (agc == 2)
	{
		fdesc = open(agv[1], O_RDONLY);
		if (fdesc == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(agv[0]);
				_eputs(": 0: Can't open");
				_eputs(agv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inf->readfd = fdesc;
	}
	populate_env_list(inf);
	read_history(inf);
	hsh(inf, agv);
	return (EXIT_SUCCESS);
}
