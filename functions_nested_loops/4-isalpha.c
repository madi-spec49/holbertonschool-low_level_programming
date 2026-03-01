#include "main.h"

/**
 * _isalpha - checks if a character is alphabetic
 * @c: the character to check
 *
 * Return: 1 if @c is a letter (lowercase or uppercase),
 *         0 otherwise
 *
 * Description: This function tests whether the given character
 *              is an alphabetic letter. It mimics the behavior
 *              of the standard library function isalpha.
 */

int _isalpha(int c)
{
	if (c >= 'a' && c  <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
