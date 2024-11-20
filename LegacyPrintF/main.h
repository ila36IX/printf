#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>

void got_percent(va_list arg, char c, int *printed);
void got_percent_N1(va_list arg, char c, int *printed);
int _putchar(char c);
void _puts(char *str, int *printed);
int _printf(const char *format, ...);
int _strlen(const char *s);
char *_itoa(long i);
int print_any_base(unsigned int n, int base, int to_lower);
void _puts_NP_case(char *str, int *printed);
int _putchar_NP_case(char c);
int print_ulongint(unsigned long n);
int print_pointer(unsigned long n);
int print_by_N3(va_list arg, char c1, char c2, char c3, int *printed);
int plus_space_case(va_list arg, char c1, char c2, char c3, int *printed);
int hash_case(va_list arg, char c1, char c2, char c3, int *printed);

#endif /* _MAIN_H */
