/*Test "c" flag without bonus*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *s, ...);

void test_c_flag(int (*f)(const char *s, ...))
{
	int return_value;

	return_value = f("Printing character: %c", 'A');
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("Printing lowercase: %c", 'z');
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("Printing number as char: %c", '7');
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("Printing special char: %c", '!');
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("First: %c, Second: %c, Third: %c", 'H', 'i', '!');
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("Hello %c World", 'X');
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("Non-printable: %c", '\t');
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%c%c%c%c", '1', '3', '3', '7');
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%c%c%c%c", '1', '3', '3', '7');
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%c", 0b11111101100001);
	printf("\nReturn value: [%d]\n", return_value);

	return_value = f("%c", 0b1111111111101101100);
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
