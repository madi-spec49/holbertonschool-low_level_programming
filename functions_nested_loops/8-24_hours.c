#include "main.h"

/**
 * jack_bauer - prints every minute of the day of Jack Bauer
 *
 * Description: This function prints all minutes of the day
 * in the format HH:MM, starting from 00:00 up to 23:59.
 *
 * Return: void
 */
void jack_bauer(void)
{
	int h, m, t, u;

	for (h = 0; h <= 23; h++)
	{
		for (m = 0; m <= 59; m++)
		{
			t = h / 10;
			u = h % 10;
			_putchar(t + '0');
			_putchar(u + '0');
			_putchar(':');

			t = m / 10;
			u = m % 10;
			_putchar(t + '0');
			_putchar(u + '0');
			_putchar('\n');
		}
	}
}
