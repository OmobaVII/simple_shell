#include "shell.h"

/**
 * _atoi - a function that converts a string to an integer
 * @str: the string to convert
 * Return: the converter string
 */
int _atoi(char *str)
{
	unsigned int i, digits;
	int n = 0;
	int n_test;

	n_test = INT_MAX;
	for (digits = 0; n_test != 0; digits++)
		n_test = n_test / 10;
	for (i = 0; str[i] != '\0' && i < digits; i++)
	{
		n = n * 10;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if ((i == digits - 1) && (str[i] - '0' > INT_MAX % 10))
			return (-1);
		n = n + str[i] - '0';
		if ((i == digits - 2) && (str[i + 1] != '\0') && (n > INT_MAX / 10))
			return (-1);
	}
	if (i > digits)
		return (-1);
	return (n);
}
/**
 * create_path - Combines two strings one representing the path directory and
 * another representing the command file
 * @dir: Representing the path directory
 * @command: Representing a file in the path directory
 * Return: A string representing the full path of the command
 */
char *create_path(char *dir, char *command)
{
	int a, b, dir_len, command_len, len;
	char *built;

	if (dir == NULL || command == NULL)
		return (NULL);
	dir_len = _strlen(dir) + 1;
	command_len = _strlen(command) + 1;
	len = dir_len + command_len;

	built = malloc(sizeof(char) * len);
	if (built == NULL)
		return (NULL);

	for (a = 0; a < len; a++)
	{
		for (b = 0; dir[b] != '\0'; b++, a++)
			built[a] = dir[b];
		built[a] = '/';
		a++;
		for (b = 0; command[b] != '\0'; b++, a++)
			built[a] = command[b];
	}
	built[--a] = '\0';
	return (built);
}
/**
 * print_message - a function that prints a string to the standard output
 * @string: the string to print
 * Return: void
 */
void print_message(char *string)
{
	long num, len;

	num = _strlen(string);
	len = write(STDOUT_FILENO, string, num);
	if (len != num)

	{
		perror("fatal error");
		exit(1);
	}
}
/**
 * _puts3 - a function that writes a string to standard output
 * @string: the string to write
 * Return: number of chars written
 */
ssize_t _puts3(char *string)
{
	ssize_t a, len;

	for (a = 0; string[a]; a++)
		;

	len = write(1, string, a);
	if (len != a)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
