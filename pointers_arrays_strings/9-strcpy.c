#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src to dest
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int index;

	for (index = 0; src[index] != '\0'; index++)
		dest[index] = src[index];

	dest[index] = '\0';

	return (dest);
}
