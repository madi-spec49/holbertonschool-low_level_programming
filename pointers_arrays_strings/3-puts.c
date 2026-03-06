#include <stdio.h>
#include "main.h"

/**
* 
* _puts - prints a string, followed by a new line
* Description: function that prints a string, followed by a new line
* @s: pointer to the string
*
* Return: The length of the string.
*
*/
void _puts(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }
    putchar('\n');
}
