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
