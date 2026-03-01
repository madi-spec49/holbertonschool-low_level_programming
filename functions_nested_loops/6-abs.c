#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 *
 * @n: the integer to evaluate
 *
 * Description: This function calculates and returns the absolute value
 * of the given integer. If the number is negative, it returns its
 * positive equivalent; if it is zero or positive, it returns the number
 * unchanged.
 *
 * Return: the absolute value of the integer n
 */

int _abs(int n)
{
	if (n > 0)
		return (n);
	else if (n == 0)
		return (0);
	else
		return (-n);
}
