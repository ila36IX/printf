/*Test mix flag without bonus*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

int	ft_printf(const char *s, ...);

void test_p_flag(int (*f)(const char *s, ...), void *p, void *pp)
{
	int return_value;

	return_value = f("%p", p);
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%c%s%d%u%x%X%p%%",'a', "Hello world", INT_MAX, UINT_MAX, UINT_MAX, 0, p);
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%c%s%d%u%x%X%p%%", 'B', "Testing", -42, 42, 0xFF, 0xFF, (void*)0xDEADBEEF);
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("Limits: %c %s %d %u %x %X %p %%", 
		  127,
		  "Extreme Test",
		  INT_MIN,
		  UINT_MAX,
		  UINT_MAX,
		  UINT_MAX,
		  (void*)UINTPTR_MAX
		  );
	printf("\nReturn value: [%d]\n", return_value);

	/*return_value = f("%c %s %d %u %x %X %p %%", */
	/*	  'Z', */
	/*	  "Short String", */
	/*	  -9999, */
	/*	  9999, */
	/*	  0xABCD, */
	/*	  0xABCD, */
	/*	  (void*)0x87654321*/
	/*	  );*/
	/*printf("\nReturn value: [%d]\n", return_value);*/
	/**/
	/*return_value = f("%c%c! %s%s %d%d %u%u %x%X %p%p %%%%", */
	/*	  'H', 'i', */
	/*	  "Hello", "World", */
	/*	  -123, 456, */
	/*	  789, 012, */
	/*	  0xAA, 0xBB, */
	/*	  (void*)0x11223344, (void*)0x55667788*/
	/*	  );*/
	/*printf("\nReturn value: [%d]\n", return_value);*/
	/**/
	/*return_value = f("Char is %c, Number is %d, Hex is 0x%x, Pointer %p, String: %s %%", */
	/*	  'X', -42, 255, (void*)0xDEADBEEF, "Hello alien! how are you felling? board :("*/
	/*	  );*/
	/*printf("\nReturn value: [%d]\n", return_value);*/
	/**/
	/*return_value = f("%c %s %d %u %x %X %p %%", */
	/*	  0, */
	/*	  "No please just don't give mw zeros I hate theme from math classes :)", */
	/*	  0, */
	/*	  0, */
	/*	  0, */
	/*	  0, */
	/*	  (void*)0*/
	/*	  );*/
	/*printf("\nReturn value: [%d]\n", return_value);*/
	/**/
	/*return_value = f("%c %s %d %u %x %X %p %c %s %d %%", */
	/*	  'A', "Best", -1, 1, 0xA, 0xB, (void*)0x1234, */
	/*	  'B', "School", -2*/
	/*	  );*/
	/*printf("\nReturn value: [%d]\n", return_value);*/
	/**/
	/*return_value = f("%p %p%s %p %%", */
	/*	  p,*/
	/*	  pp,*/
	/*	  "Why you doing this? I love Dexter! I do the some he does to code :)",*/
	/*	   p*/
	/*	  );*/
	/*printf("\nReturn value: [%d]\n", return_value);*/
}


int main(int ac, char **av)
{
	setbuf(stdout, NULL);
	if (ac < 2)
	{
		printf("%s org/you\n", av[0]);
		return (0);
	}
	if (strcmp(av[1], "org") == 0)
		test_p_flag(printf, (void *)0x7ffc5183bfc0, (void *)0x7ffdb8616ca0);
	else if (strcmp(av[1], "you") == 0)
		test_p_flag(ft_printf, (void *)0x7ffc5183bfc0, (void *)0x7ffdb8616ca0);
	else
		printf("Unkown flag\n");
}
