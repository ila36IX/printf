#include "main.h"

/**
 * _puts_NP_case - print any string normaly excepte
 * non printable charcters by print them this way: /x
 * followed by the ASCII code in hexa(2 chars).
 *
 * @str: Character
 * @printed: Pointer to the int that _printf will return
 * Return: Nothing
 */
void _puts_NP_case(char *str, int *printed)
{
	char c;
	int i = 0;

	if (str)
	{

		while (*(str + i) != '\0')
		{
			c = *(str + i);
			*printed += _putchar_NP_case(c);
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

/**
 * _putchar_NP_case - print any character normaly excepte
 * non printable charcters by print them as following: /x
 * followed by the ASCII code in hexa(2 chars).
 *
 * @c: Character
 * Return: Number of charcter printed
 */
int _putchar_NP_case(char c)
{
	if (c >= 0 && c <= 15)
	{
		return (_printf("\\x0%X", (unsigned int) c));
	}
	else if ((c > 15 && c < 32) || (c >= 127))
	{
		return (_printf("\\x%X"), (unsigned int) c);
	}
	else
	{
		return (_putchar(c));
	}
}
