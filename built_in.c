#include "shell.h"
/**
 * unset_env - a function that unsets an environment variable
 * @vars: a pointer to a struct of variables
 * Return: void
 */
void unset_env(vars_t *vars)
{
	char **key, **newenv;
	unsigned int a, b;

	if (vars->array_tokens[1] == NULL)
	{
		error_message(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}
	key = find_key(vars->env, vars->array_tokens[1]);
	if (key == NULL)
	{
		error_message(vars, ": No variable to unset");
		return;
	}
	for (a = 0; vars->env[a] != NULL; a++)
		;
	newenv = malloc(sizeof(char *) * a);
	if (newenv == NULL)
	{
		error_message(vars, NULL);
		vars->status = 127;
		new_exit(vars);
	}
	for (a = 0; vars->env[a] != *key; a++)
	{
		newenv[a] = vars->env[a];
	}
	for (b = a + 1; vars->env[b] != NULL; b++, a++)
		newenv[a] = vars->env[b];
	newenv[a] = NULL;
	free(*key);
	free(vars->env);
	vars->env = newenv;
	vars->status = 0;
}
/**
 * set_env - a function that sets an environment variable
 * @vars: a pointer to an array of variables
 * Return: void
 */
void set_env(vars_t *vars)
{
	char **key;
	char *var;

	if (vars->array_tokens[1] == NULL || vars->array_tokens[2] == NULL)
	{
		error_message(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}
	key = find_key(vars->env, vars->array_tokens[1]);
	if (key == NULL)
	{
		add_new(vars);
	}
	else
	{
		var = add_value(vars->array_tokens[1], vars->array_tokens[2]);
		if (var == NULL)
		{
			error_message(vars, NULL);
			free(vars->buffer);
			free(vars->array_tokens);
			free(vars->commands);
			free_env(vars->env);
			exit(127);
		}
		free(*key);
		*key = var;
	}
	vars->status = 0;
}
/**
 * _env - a function that prints the current environment variable
 * @vars: an arrays of variables
 * Return: void
 */
void _env(vars_t *vars)
{
	unsigned int a;

	for (a = 0; vars->env[a]; a++)
	{
		_puts(vars->env[a]);
		_puts("\n");
	}
	vars->status = 0;
}
/**
 * new_exit - a function that exits a program
 * @vars: an array of variables
 * Return: void
 */
void new_exit(vars_t *vars)
{
	int a = 0;

	if (_strcmprev(vars->array_tokens[0], "exit")
			== 0 && vars->array_tokens[1] != NULL)
	{
		a = _atoi(vars->array_tokens[1]);
		if (a == -1)
		{
			vars->status = 2;
			error_message(vars, ": Illegal number: ");
			print_message(vars->array_tokens[1]);
			print_message("\n");
			return;
		}
		vars->status = a;
	}
	free(vars->commands);
	free(vars->array_tokens);

	free_env(vars->env);
	free(vars->buffer);
	exit(vars->status);
}
/**
 * builtin_check - a function that checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function
 */
void (*builtin_check(vars_t *vars))(vars_t *vars)
{
	unsigned int a;
	builtins_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"cd", new_cd},
		{"help", new_help},


		{NULL, NULL}};

	for (a = 0; check[a].f != NULL; a++)
	{
		if (_strcmprev(vars->array_tokens[0], check[a].name) == 0)
			break;
	}
	if (check[a].f != NULL)
		check[a].f(vars);
	return (check[a].f);
}
