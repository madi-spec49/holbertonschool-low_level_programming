#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to extract the last digit from
 *
 * Return: value of the last digit
 */
int print_last_digit(int n)
{
	int i = n % 10;

	if (i < 0)
		i = -i;
	_putchar('0' + i);
	return (i);
}
