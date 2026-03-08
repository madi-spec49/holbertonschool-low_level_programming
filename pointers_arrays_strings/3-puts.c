#include "main.h"

/**
*  _puts - Prints a string followed by a new line
* @str: The string to print
*
* Description: Write a function that prints a string, followed by a new line
*
* Return: The length of the string.
*/
void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
