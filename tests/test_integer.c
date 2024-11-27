/*Test "i" flag without bonus*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *s, ...);

void test_d_flag(int (*f)(const char *s, ...))
{
	int return_value;

	return_value = f("%i", 1337);
	printf("\nReturn value: [%i]\n", return_value);

	return_value = f("%i%i", -1, -1337);
	printf("\nReturn value: [%i]\n", return_value);

	return_value = f("%i%i", INT_MAX, INT_MIN);
	printf("\nReturn value: [%i]\n", return_value);

	return_value = f("%i%i", (long)INT_MAX + 1337, (long)INT_MIN - 1337);
	printf("\nReturn value: [%i]\n", return_value);

	return_value = f("%i%i%i%i%i", 0, 10, 100, 10000, 100000);
	printf("\nReturn value: [%i]\n", return_value);

	return_value = f("%i", -99999999999999999);
	printf("\nReturn value: [%i]\n", return_value);

	return_value = f("%i/%i/%i/%i", -999999, 'a', 'l', 'i');
	printf("\nReturn value: [%i]\n", return_value);

	return_value = f("%i%i%i%i%i%i%i%i%i%i", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	printf("\nReturn value: [%i]\n", return_value);
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
		test_d_flag(printf);
	else if (strcmp(av[1], "you") == 0)
		test_d_flag(ft_printf);
	else
		printf("Unkown flag\n");
}
