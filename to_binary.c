#include "main.h"

/**
 * to_binary - Prints integer in binary (base 2)
 *
 * @n: The integer
 * Return: Number of characters printed
 */
int to_binary(unsigned int n)
{

	if (n / 2 == 0)
	{
		return (_putchar(n % 2 + '0'));
	}
	else
	{
		return (to_binary(n / 2) + _putchar(((int)(n % 2)) + '0'));
	}

}
