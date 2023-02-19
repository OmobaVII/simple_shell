#include "shell.h"

/**
 * new_environment - a function that creates the shell environment
 * @env: environment passed to main
 * Return: the new environment
 */

char **new_environment(char **env)
{
	char **environment = NULL;
	size_t a;

	for (a = 0; env[a] != NULL; a++)
		;
	environment = malloc(sizeof(char *) * (a + 1));
	if (environment == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (a = 0; env[a] != NULL; a++)
		environment[a] = _strdup(env[a]);
	environment[a] = NULL;
	return (environment);
}
/**
 * free_env - a function that free the shell's environment
 * @env: shell's environment to be freed
 * Return: void
 */
void free_env(char **env)
{
	unsigned int a;

	for (a = 0; env[a] != NULL; a++)
		free(env[a]);
	free(env);
}

/**
 * chdir_env - a function that goes to the directory
 * that has the address of the environment variable
 * @vars: vars variable of struct vars_t
 * @str: name of the environment var to find
 * Return: Void
 */
void chdir_env(vars_t *vars, char *str)
{
	int len, a;

	len = _strlen(str);
	a = find_environ_index(*vars, str);
	chdir((vars->env[a]) + len + 1);
}
/**
 * find_environ_index - a function that finds the index
 * of an enviromental variable
 * @vars: structure with variables will be used
 * @str: environmental variable that needs to be found
 * Return: index of the environmental varaible
 */

int find_environ_index(vars_t vars, char *str)
{
	int a, b, len;

	len = _strlen(str);
	for (a = 0; vars.env[a] != NULL; a++)
	{
		for (b = 0; b < len; b++)
		{
			if (vars.env[a][b] != str[b])
				break;
		}
		if (b == len && vars.env[a][b] == '=')
			return (a);
	}
	return (-1);
}
