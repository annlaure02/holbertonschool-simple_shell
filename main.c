#include "shell.h"

/**
 * main - execute the shell
 *
 * Return: 1 if success
 */

void ctrl_c(int signal)
{
	(void)signal;
		printf("\n;) ");
}

int main(void)
{
	int status = 1;
	char *line;
	char **argv;

	signal(SIGINT, ctrl_c);
	while (1)
	{
		status = isatty(0);

		if (status == 1)
			printf(";) ");

		line = readline();
		if (line == NULL || (_strcmp(line, "exit")) == 0)
		{
			free(line);
			return (0);
		}

		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			exit_shell();
		}
		if (_strcmp(line, "environ") == 0)
		{
			print_env();
			free(line);
			continue;
		}
		argv = split_string(line);
		if (argv == NULL)
		{
			free(line);
			free(argv);
			continue;
		}
		status = exec_cmd(argv);
		free(line);
		free(argv);
	}
	return (0);
}
