#include "main.h"

/**
 * print_any_base - Prints integer in any base
 *
 * @n: The integer
 * @to_lower: 1 to print the hexa in lower case,
 * and 0 to print in upper case.
 * @base: Will be printed in like 2, 10, 8, 16 ...
 * Return: Number of characters printed
 */
int print_any_base(unsigned int n, int base, int to_lower)
{
	int r = n % base;

	if (n / base == 0)
	{
		if (r  < 10)
			return (_putchar(r + '0'));
		else if (r >= 10 && to_lower)
			return (_putchar(r - 10 + 'a'));
		else
			return (_putchar(r - 10 + 'A'));
	}

	else
	{
		if (r < 10)
			return (print_any_base(n / base, base, to_lower) + _putchar(r + '0'));
		else if (r >= 10 && to_lower)
			return (print_any_base(n / base, base, to_lower) + _putchar(r - 10 + 'a'));
		else
			return (print_any_base(n / base, base, to_lower) + _putchar(r - 10 + 'A'));
	}
}
