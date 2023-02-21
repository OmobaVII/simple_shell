#include "shell.h"
/**
 * factorial -  return the factorial of a given number
 *
 * @n: int to check
 *
 * Return: the factorial number of n
 */
/*This is a simple code to calculate the factorial of a given variable n */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n == 0)
	{
		return (1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}
