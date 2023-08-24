#include "main.h"
#include <stdarg.h>

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

			if (next_char == 'c')
				_putchar(va_arg(inputs, int));

			else if (next_char == 's')
				_puts(va_arg(inputs, char *));

			else if (next_char == '%')
				_putchar('%');
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


