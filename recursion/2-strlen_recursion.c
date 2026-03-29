#include "main.h"

/**
 * _strlen_recursion - a function that prints the lenght of a string
 * @s: An input string to mesure
 * Return: 0 success
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
