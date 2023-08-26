#include "main.h"

/**
 * got_percent - print %s and %c and %%
 *
 * @arg: The variadic arguments of _printf
 * @c: Next charachter after % sign
 * @printed: Pointed to the integer that
 * _printf will return.
 * Return: Integer of char. printed
 */

void got_percent(va_list arg, char c, int *printed)
{
	switch (c)
	{
	case 'c':
		*printed += _putchar(va_arg(arg, int));
		break;

	case 's':
		_puts(va_arg(arg, char *), printed);
		break;

	case '%':
		*printed += _putchar('%');
		break;

	case '\0':
		*printed = -1;
		break;

	case 'i':
	case 'd':
		_puts(_itoa(va_arg(arg, int)), printed);
		break;

	case 'b':
		*printed += to_binary(va_arg(arg, int));
		break;

	default:
		*printed += _putchar('%');
		*printed += _putchar(c);
	}
}
