#include "shell.h"

/**
 * new_cd - a function that changes the current working directory
 * @vars: the input parameter from the user
 * Return: void
 */
int new_cd(vars_t *vars)
{
	int index;

	if (vars->array_tokens[1] == NULL)
	{
		index = find_environ_index(*vars, "HOME");
		chdir((vars->env[index]) + 5);
	}
	else if (_strcmprev(vars->array_tokens[1], "-") == 0)
		print_str(vars->array_tokens[1], 0);
	else
		chdir(vars->array_tokens[1]);
	exit(vars->status);
}
/**
 * print_cd - a function that prints error when cd argument is invalid
 * @vars: the parameter
 * Return: Void
 */
void print_cd(vars_t *vars)
{
	print_str("-bash: cd: ", 1);
	print_str(vars->array_tokens[1], 1);
	print_str(": invalid option", 0);
	print_str("cd: usage: cd [-] [--]", 0);
}
/**
 * print_cd_2 - a function that prints error message
 * if cd argument doesnt exist
 * @vars: the variable parameter
 * Return: void
 */
void print_cd_2(vars_t *vars)
{
	print_str("-bash: cd: ", 1);
	print_str(vars->array_tokens[1], 1);
	print_str(": Not a directory", 0);
}
