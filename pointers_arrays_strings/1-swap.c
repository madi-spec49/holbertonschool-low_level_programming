#include <stdio.h>
#include "main.h"
/**
*
*  Description: a function permute a values
*
*
*
*/
void swap_int(int *a, int *b)

{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
