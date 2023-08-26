#include "main.h"
#include <stdio.h>
/**
 * _itoa - Print an integer to stdio
 *
 * @i: integer
 * Return: Nothing
 */
char *_itoa(int i)
{
	int a, rest, j = 0;
	int is_negative = 0;
	char *str = malloc(sizeof(char) * 20);

	if (i == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (i < 0)
	{
		is_negative = 1;
		i *= (-1);
	}
	while (i)
	{
		rest = i % 10;
		str[j] = rest + '0';
		i /= 10;
		j++;
	}
	if (is_negative == 1)
	{
		str[j] = '-';
		j++;
	}

	str[j] = '\0';

	for (a = 0; a < j / 2; a++)
	{
		char holder = str[a];

		str[a] = str[j - a - 1];
		str[j - a - 1] = holder;
	}

	return (str);
}

