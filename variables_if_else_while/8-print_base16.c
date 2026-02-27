#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: prints all the numbers
 *
 *Return: Always 0 (Success)
 *
 */
int main(void)

{
	char n;
	char i;

	for (n = '0'; n <= '9'; n++)
	{
		putchar(n);
	}
	for (i = 'a' ; i <= 'f'; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);

}
