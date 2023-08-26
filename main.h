#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>

void got_percent(va_list arg, char c, int *printed);
int _putchar(char c);
void _puts(char *str, int *printed);
int _printf(const char *format, ...);
int _strlen(const char *s);
char *_itoa(long i);

#endif /* _MAIN_H */
