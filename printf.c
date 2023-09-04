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
		if (format[i] == '%' && (format[i + 1] == ' ' ||
					format[i + 1] == '+' ||
					format[i + 1] == '#'))
		{
			char N3[3] = {'\0', '\0', '\0'};
			int index = 0;

			while (format[index + i] && index <= 2)
			{
				N3[index] = format[index + i + 1];
				index++;
			}
			i += print_by_N3(inputs, N3[0], N3[1], N3[2], &char_printed);
		}
		else if (*(format + i) == '%')
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
