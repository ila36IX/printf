#include "main.h"

/**
 * _puts - Print string in stdout
 *
 * @str: The string
 * @printed: Pointer to the integer
 * the _printf will return
 * Return: Nothing
 */

void _puts(char *str, int *printed)
{
	char c;
	int i = 0;

	if (str)
	{

		while (*(str + i) != '\0')
		{
			c = *(str + i);
			*printed += _putchar(c);
			i++;
		}
	}
	else
	{
		*printed += _putchar('(');
		*printed += _putchar('n');
		*printed += _putchar('u');
		*printed += _putchar('l');
		*printed += _putchar('l');
		*printed += _putchar(')');
	}

}
