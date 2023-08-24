#include "main.h"

/**
 * _printf - %s %c cases
 *
 * @format: charachte string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, length = _strlen(format);
	int char_printed = 0;
	va_list inputs;

	va_start(inputs, format);

	for (i = 0; i < length; i++)
	{
		if (*(format + i) == '%')
		{
			char next_char = *(format + i + 1);

			char_printed += got_percent(inputs, next_char);
			i++;
		}
		else
		{
			char_printed++;
			_putchar(*(format + i));
		}
	}
	va_end(inputs);
	return (char_printed);

}

/**
 * got_percent - print %s and %c and %%
 *
 * @arg: The variadic arguments of _printf
 * @c: Next charachter after % sign
 * Return: Integer of char. printed
 */

int got_percent(va_list arg, char c)
{
	if (c == 'c')
	{
		_putchar(va_arg(arg, int));
		return (1);
	}
	else if (c == 's')
	{
		char *string = va_arg(arg, char *);

		_puts(string);
		return (_strlen(string));
	}
	else if (c == '%')
	{
		_putchar('%');
		return (1);
	}
	return (0);
}
