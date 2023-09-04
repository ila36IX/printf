#include "main.h"


/**
 * got_percent_N1 - print every char after % case
 *
 * @arg: The variadic arguments of _printf
 * @c: Next charachter after % sign
 * @printed: Pointed to the integer that _printf will return.
 * Return: Integer of char. printed
 */
void got_percent_N1(va_list arg, char c, int *printed)
{
	switch (c)
	{
	case 'S':
		_puts_NP_case(va_arg(arg, char *), printed);
		break;
	case 'p':
		*printed += print_pointer(va_arg(arg, unsigned long));
		break;

	case 'i':
	case 'd':
		_puts(_itoa(va_arg(arg, int)), printed);
		break;

	default:
		*printed += _putchar('%');
		*printed += _putchar(c);
	}
}
