#include <stdio.h>
#include <stdlib.h>

/**
 * _atoi - Convert a string to an integer
 * @s:the string to convert
 *
 * Return: the integer value
 */
int _atoi(char *s)
{
	int num = 0;
	int sign = 1;
	int i = 0;

	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num * sign);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s num1 num2\n", argv[0]);
		return (1);
	}
	printf("%d\n", _atoi(argv[1]) * _atoi(argv[2]));
	return (0);
}
