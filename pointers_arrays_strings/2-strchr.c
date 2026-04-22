#include "main.h"
#include <stdio.h>

/**
 * _strchr - Locates a character in a string
 * @s: The string to search
 * @c: The character to find
 *
 * Return: Pointer to first occurrence of c in s, or NULL
 */
char *_strchr(char *s, char c)
{
	int a;

	while (1)
	{
		a = *s++;
		if (a == c)
			return (s - 1);
		if (a == 0)
			return (NULL);
	}
}
