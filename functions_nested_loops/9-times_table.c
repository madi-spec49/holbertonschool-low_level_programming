#include "main.h"

/**
 * times_table - prints the 9 times table, starting from 0
 *
 * Description: This function prints the multiplication table of 9.
 * Each row contains the products of numbers from 0 to 9 multiplied
 * by the row number, separated by commas and spaces.
 *
 * Return: void
 */
void times_table(void)
{
	int r, c, m;

	for (r = 0; r <= 9; r++)
	{
		for (c = 0; c <= 9; c++)
		{
			m = r * c;

			if (c == 0)
				_putchar(m + '0');
			else
			{
				_putchar(',');
				_putchar(' ');

				if (m < 10)
					_putchar(' ');

				if (m >= 10)
				{
					_putchar((m / 10) + '0');
					_putchar((m % 10) + '0');
				}
				else
					_putchar(m + '0');
			}
		}
		_putchar('\n');
	}
}
