/*Test "-" flag (bonus)*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *s, ...);

void test_zeroMinusPresesion_flag(int (*f)(const char *s, ...))
{
	int return_value;

	return_value = f("%-x", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-u", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-d", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-X", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-16X", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-16x", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-16d", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-16i", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-16u", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-15x", INT_MAX);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-20d", INT_MIN);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-11d", INT_MIN);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-10X", 1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-10d", 18);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-i", -1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-i", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-10x", -1337);
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
