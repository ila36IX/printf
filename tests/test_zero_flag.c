/*Test "0" flag (bonus)*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *s, ...);

void test_zeroMinusPresesion_flag(int (*f)(const char *s, ...))
{
	int return_value;

	return_value = f("%0d", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%016d", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%010d", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20d", INT_MIN);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%11d", INT_MIN);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%010d", 1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%010d", 18);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%0d", -1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%0d", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%0d", -1337);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%010c", 'a');
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%010x", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%010X", UINT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
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
		test_zeroMinusPresesion_flag(printf);
	else if (strcmp(av[1], "you") == 0)
		test_zeroMinusPresesion_flag(ft_printf);
	else
		printf("Unkown flag\n");
}
