#include <stdio.h>
#include "main.h"
/**
* _strlen - retourne la longueur d'une chaine
*
* Description:la chaine de caractere
*
* longeur de la chaine
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
