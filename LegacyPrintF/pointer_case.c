#include "main.h"

/**
 * print_ulongint - Prints long unsigned int
 *
 * @n: long unsigned integer
 * Return: Number of characters printed
 */
int print_ulongint(unsigned long n)
{
	int r = n % 16;

	if (n / 16 == 0)
	{
		if (r  < 10)
			return (_putchar(r + '0'));
		else
			return (_putchar(r - 10 + 'a'));
	}

	else
	{
		if (r < 10)
			return (print_ulongint(n / 16) + _putchar(r + '0'));
		else
			return (print_ulongint(n / 16) + _putchar(r - 10 + 'a'));
	}
}


/**
 * print_pointer - Prints long unsigned inti (Pointer)
 *
 * @n: long unsigned integer
 * Return: Number of characters printed
 */
int print_pointer(unsigned long n)
{
	if (n == 0)
		return (_printf("(nil)"));

	_printf("0x");
	return (print_ulongint(n) + 2);
}
