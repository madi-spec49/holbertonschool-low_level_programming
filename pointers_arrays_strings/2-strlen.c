#include <stdio.h>
#include "main.h"

/**
* _strlen - Returns the length of a string
* @s: pointer to the string
* Description: Calculates and returns the number of characters
* in the string pointed to by s.
*
* Return: The length of the string.
*/
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{	count++;
	}

	return (count);
}
