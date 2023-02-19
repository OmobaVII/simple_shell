#include "shell.h"

/**
 * _strcmp - a function that compares two strings
 * @str1: First string
 * @str2: Second string
 * Return: 0 if strings match and -1 otherwise
 */

int _strcmp(char *str1, char *str2)
{
	int a;

	if (_strlen(str1) != _strlen(str2))
	{
		return (-1);
	}
	for (a = 0; str1[a] != '\0'; a++)
	{
		if (str1[a] != str2[a])
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * simple_error - a function that prints simple error
 * Return: void
 */

void simple_error(void)
{
	perror("Fatal Error");
	exit(100);
}
/**
 * print_error - a function that prints an error message if command not found
 * @argv: the name of the shell program
 * @count: the number of commands running on the shell
 * @command: The command not found
 * Return: void
 */
void print_error(char *argv, int count, char *command)
{
	print_str(argv, 1);
	print_str(": ", 1);
	print_number(count);
	print_str(": ", 1);
	print_str(command, 1);
}
/**
 * execute_error - a function that prints execution errors
 * @argv: the name of the shell program
 * @count: the number of commands running on the shell
 * @temp_command: the command that fails
 */
void execute_error(char *argv, int count, char *temp_command)
{
	print_error(argv, count, temp_command);
	print_str(": ", 1);
	perror("");
	exit(1);
}
/**
 * print_str - a function that prints a string character by character
 * @str: the string to print
 * @newline: if the interger is zero a newline is printed
 * Return: void
 */
void print_str(char *str, int newline)
{
	int a;

	if (str == NULL)
		str = "(null)";
	for (a = 0; str[a] != '\0'; a++)
	{
		write(STDOUT_FILENO, &str[a], 1);
	}
	if (newline == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
	}
}
