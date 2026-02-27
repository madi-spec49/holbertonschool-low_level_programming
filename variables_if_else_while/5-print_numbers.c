#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: prints all single numbers
 *
 * Return: 0 (Success)
 */
int main(void)
{
	char n;

	for (n = '0'; n <= '9'; n++)
		putchar(n);
	putchar('\n');
	return (0);
}
