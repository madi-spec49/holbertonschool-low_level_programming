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
int _strlen(char *s)

{
	int count = 0;

	while (s[count] != '\0')
	{	count++;
	}

	return (count);
}
