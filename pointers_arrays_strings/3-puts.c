#include <stdio.h>
#include "main.h"
/**
* _puts- Returns the length of a string
* @s: pointer to the string
*
* Description: function that prints a string, followed by a new line
*
* Return: The length of the string.
*
*/

void _puts(char *s)

{
	int i = 0;

	while (s[i] != '\0')
	{
		putchar(s[i]);
		i++;
	}
	putchar('\n');
}
