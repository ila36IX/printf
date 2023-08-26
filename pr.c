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

	if (!format)
		return (-1);

	va_start(inputs, format);

	for (i = 0; i < length; i++)
	{
		if (*(format + i) == '%')
		{
			char next_char = *(format + i + 1);

			got_percent(inputs, next_char, &char_printed);
			i++;
		}
		else
		{
			char_printed += _putchar(*(format + i));
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

void got_percent(va_list arg, char c, int *printed)
{
	if (c == 'c')
	{
		*printed += _putchar(va_arg(arg, int));
	}
	else if (c == 's')
	{
		_puts(va_arg(arg, char *), printed);
	}
	else if (c == '%')
	{
		*printed += _putchar('%');
	}
	else if (c == '\0')
	{
		*printed = -1;
	}
	else if (c == 'i' || c == 'd')
	{
		_puts(_itoa(va_arg(arg, long)), printed);
	}
	else
	{
		*printed +=_putchar('%');
		*printed += _putchar(c);
	}
}
