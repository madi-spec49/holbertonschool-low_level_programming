#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: The string to print
 */
void puts_half(char *str)

{
	int i, j, k;

	i = 0;

	while (str[i] != '\0')
		i++;

	if (i % 2 == 0)
	{
		for (k = i / 2; str[k] != '\0'; k++)
			_putchar(str[k]);
	} else if (i % 2)
	{
		for (j = (i - 1) / 2; j < i - 1; j++)
			_putchar(str[j + 1]);
	}
	_putchar('\n');
}
