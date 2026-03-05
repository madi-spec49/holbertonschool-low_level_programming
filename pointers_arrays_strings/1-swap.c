#include <stdio.h>
#include "main.h"

/**
* swap_int - Swaps the values of two integers
*
* Description: a function permute a values
*
* @a: pointer to the first integer
* @b: pointer to the second integer
*
*/
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
