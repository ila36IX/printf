/*Test "mind1" flag without bonus*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *s, ...);
/*
 * test_*_flag: this function desgined to run the some test
 * uisng different version of printf to do diff later
 * @f: Pointer to function with the some prototype as printf
 *
 * Return: None
 */
void test_d_flag(int (*f)(const char *s, ...))
{
	int return_value;
	return_value = f("%.03s", NULL);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%3.1s", NULL);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%9.1s", NULL);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-3.1s", NULL);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-9.1s", NULL);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.0i", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.i", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%5.0i", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%5.i", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-5.0i", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-5.i", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.0d", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.d", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%5.0d", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%5.d", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-5.0d", 0);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-5.d", 0);
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
		test_d_flag(printf);
	else if (strcmp(av[1], "you") == 0)
		test_d_flag(ft_printf);
	else
		printf("Unkown flag\n");
}
