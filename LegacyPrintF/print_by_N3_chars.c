#include "main.h"

/**
 * print_by_N3 - It takes as argument three next characters after %
 * and print based on its conversion specifiers.
 *
 * @arg: List of arguments that printf got
 * @c1: first character after %
 * @c2: Second character after %
 * @c3: Third character after %
 * @printed: Pointer to the integer that printf will return
 * Return: Number of characters that acually are specifiers.
 */
int print_by_N3(va_list arg, char c1, char c2, char c3, int *printed)
{
	if (c1 == ' ' || c1 == '+')
	{
		return (plus_space_case(arg, c1, c2, c3, printed));
	}

	return (hash_case(arg, c1, c2, c3, printed));

}


/**
 * hash_case - Adds a prefix(0x - 00 - 0X) based on format specifier used
 *
 * @arg: List of arguments that printf got
 * @c1: first character after %
 * @c2: Second character after %
 * @c3: Third character after %
 * @printed: Pointer to the integer that printf will return
 * Return: Number of characters that acually are specifiers.
 */
int hash_case(va_list arg, char c1, char c2, char c3, int *printed)
{
	unsigned int n;
	(void) c1;
	(void) c3;

	n = va_arg(arg, unsigned int);

	if (n == 0)
	{
		*printed += 1;
		return (_printf("0"));
	}
	else if (c2 == 'o')
	{
		*printed += _printf("0%o", n);
	}
	else if (c2 == 'x')
	{
		*printed += _printf("0x%x", n);
	}
	else if (c2 == 'X')
	{
		*printed += _printf("0X%X", n);
	}
	return (2);
}


/**
 * plus_space_case - Handle plus and space format (print plus on
 * positive numbers).
 *
 * @arg: List of arguments that printf got
 * @c1: first character after %
 * @c2: Second character after %
 * @c3: Third character after %
 * @printed: Pointer to the integer that printf will return
 * Return: Number of characters that acually are specifiers.
 */
int plus_space_case(va_list arg, char c1, char c2, char c3, int *printed)
{
	int n;

	if (c2 == 'd' || c2 == 'i' || c3 == 'd' || c3 == 'i')
	{
		n = va_arg(arg, int);
		if (n >= 0 && c1 == '+')
		{
			*printed += _putchar('+');
		}
		else if(n >= 0 && c1 == ' ')
		{
			*printed += _putchar(' ');
		}
		_puts(_itoa(n), printed);
	}
	if (c1 == ' ' && (c2 == 'd' || c2 == 'i'))
	{
		return (2);
	}
	else if (c1 == '+' && (c2 == 'd' || c2 == 'i'))
	{
		return (2);
	}
	else if (c1 == '+' && c2 == ' ' && (c3 == 'd' || c3 == 'i'))
	{
		return (3);
	}
	else if (c1 == ' ' && c2 == '+' && (c3 == 'd' || c3 == 'i'))
	{
		return (3);
	}
	else if (c1 == ' ' && c2 == '%')
	{
		*printed += _printf("%% ");
		return (1);
	}
	else
	{
		return (0);
	}
}
