#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Succes)
 *
 * Description: Rand number 
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
		printf("%d is positive\n", n );
		else if (0 == 0)
			     printf("%d is zero\n", n );
	if (n < 0)
		printf("%dis negative\n", n );
	return (0);
}
