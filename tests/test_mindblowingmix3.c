/*Test "mind2" flag without bonus*/
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
	return_value = f("%10.5i", -216);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%8.3i", -8473);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-10.5i", -216);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-8.3i", -8473);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%010.5i", -216);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%08.3i", -8473);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%10.5d", -216);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%8.3d", -8473);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-10.5d", -216);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-8.3d", -8473);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%010.5d", -216);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%08.3d", -8473);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%15.4d", -42);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%15.4d", -424242);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-114.24i%-174.164i" ,-608242235,-1247846882);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%0176.18i%0131.59i%-86X%---45.36X" ,-1748967713,-1568187420,124888334u,2293430389u);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%0020.149u%-99.97i" ,2945319386u,-1913054753);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-198.190i" ,-915338234);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.03s", NULL);
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
