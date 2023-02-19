#include <stdio.h>
#include <unistd.h>

/**
 * main - getppid
 *
 * Return: Always zero
 */

int main(void)
{
	printf("PID of the current process: %d\n", getppid());
	return (0);
}
