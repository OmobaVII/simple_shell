#include "shell.h"
/**
 * print_number - a function that prints a number like a single char
 * @n: the number to be printed
 * Return: the number of numbers printed
 */
int print_number(int n)
{
	int divisor, len;
	unsigned int num;

	divisor = 1;
	len = 0;

	num = n;

	for (; num / divisor > 9; )
		divisor = divisor * 10;

	for (; divisor != 0; )
	{
		len += _write_char('0' + num / divisor);
		num %= divisor;
		divisor = divisor / 10;
	}
	return (len);
}
/**
 * _write_char - function that prints a single character
 * @c: the character to be printed
 * Return: the printed character
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts_error - a function that prints to the stderr
 * @str: the string to print
 * Return: void
 */

void _puts_error(char *str)
{
	long num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)

	{
		perror("fatal error");
		exit(100);
	}
}
/**
 * error_message - prints an error message
 * @vars: a singly linked list
 * @message: the error to print
 * Return: void
 */
void error_message(vars_t *vars, char *message)
{
	char *counter;

	_puts_error(vars->argv[0]);
	_puts_error(": ");

	counter = int_converter(vars->counter);
	_puts_error(counter);
	free(counter);
	_puts_error(": ");
	_puts_error(vars->array_tokens[0]);
	if (message)
	{
		_puts_error(message);
	}
	else
		perror("");
}
/**
 * int_converter - a function that converts an unsigned int to a string
 * @counter: the unsigned int to be converter
 * Return: the converter unsigned int
 */
char *int_converter(unsigned int counter)
{
	char *intstr;
	unsigned int temp, digits;

	temp = counter;

	for (digits = 0; temp != 0; digits++)
		temp /= 10;

	intstr = malloc(sizeof(char) * (digits + 1));

	if (intstr == NULL)
	{
		perror("Fatal Error");
		exit(100);
	}

	intstr[digits] = '\0';

	for (--digits; counter; --digits)
	{
		intstr[digits] = (counter % 10) + '0';
		counter /= 10;
	}
	return (intstr);
}
