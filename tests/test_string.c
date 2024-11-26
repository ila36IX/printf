/*-Test "s" flag without bonus-*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *s, ...);

void test_c_flag(int (*f)(const char *s, ...))
{
	int return_value;

	return_value = f("%s", "Heatblast");
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%s%s", "Heatblast", "AlienX");
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%s%s", "", "");
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%s", "");
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%s", NULL);
	printf("\nReturn value: [%d]\n", return_value);

	// Very long string char
	char long_string[1000];
	memset(long_string, 'a', 999);
	long_string[999] = '\0';
	return_value = f("%s", long_string);
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
		test_c_flag(printf);
	else if (strcmp(av[1], "you") == 0)
		test_c_flag(ft_printf);
	else
		printf("Unkown flag\n");
}
