#include "main.h"

/**
 * print_sign - prints the sign of a number
 *
 * @n: the number to check
 *
 * Description: This function prints '+' if n is greater than zero,
 * '0' if n is zero, and '-' if n is less than zero.
 *
 * Return: 1 if n is positive, 0 if n is zero, -1 if n is negative.
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{	_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
