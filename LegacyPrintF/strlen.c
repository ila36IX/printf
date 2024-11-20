#include "main.h"
#include <stddef.h>

/**
 * _strlen - return the length of a string
 *
 * @s: The string
 *
 * Return: An integer
 */
int _strlen(const char *s)
{
	int length = 0;

	if (s == NULL)
		return (0);

	while (s[length] != '\0')
		length++;

	return (length);

}
