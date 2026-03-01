#include "main.h"

/**
* print_alphabet - prints the alphabet in lowercase
*
* Description: Uses a loop to print all letters from 'a' to 'z',
* followed by a new line.
*
* Return: Always 0 (Success)
*/

void print_alphabet(void)
{
	char c;

	for (c = 'a' ; c <= 'z' ; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}
