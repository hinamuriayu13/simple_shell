#include "shell.h"

/**
 * _myexit - Exits the shell with a given exit status or displays an error message
 *    if an illegal number is provided as an argument.
 * @inf: a pointer to a structure (presumably containing information
 *        about the shell)
 * Return: If inf->argv[0] != "exit", it exits with 0.
 *         If there is an exit argument and it is a valid number, it returns -2.
 *        If there is an exit argument and it is an illegal number, it returns 1 and
 *         sets inf->status and inf->err_num accordingly.
 *      If there is no exit argument, it sets inf->err_num to -1 and returns -2.
 */
int _myexit(info_t *inf)
{
	int exitcheck;

	if (inf->argv[1]) /* If there is an exit argument */
	{
		exitcheck = _erratoi(inf->argv[1]);
		if (exitcheck == -1)
		{
			inf->status = 2;
			print_error(inf, "Illegal number: ");
			_eputs(inf->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inf->err_num = _erratoi(inf->argv[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
 * _mycd - Changes the current directory of the process.
 * @inf: a pointer to a structure (presumably containing information about the shell).
 * Return: Always 0.
 */
int _mycd(info_t *inf)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!inf->argv[1])
	{
		dir = _getenv(inf, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(inf, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(inf->argv[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(inf, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(inf->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(inf, "can't cd to ");
		_eputs(inf->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(inf, "OLDPWD", _getenv(inf, "PWD="));
		_setenv(inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - Displays a message indicating that the help function call works (but
 *      the function itself is not implemented yet).
 * @inf: a pointer to a structure (presumably containing information
 *        about the shell)
 * Return: Always 0.
 */
int _myhelp(info_t *inf)
{
	char **arg_array;

	arg_array = inf->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
