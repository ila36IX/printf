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
	return_value = f("%.03s", NULL);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p6 %.0d\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p14 %.0i\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p22 %.0x\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p30 %.0u\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%15p\n", NULL);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-15p\n", NULL);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("t3 %50.0d\n", 10);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.5d", -1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.5i", -1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%020.5d", -1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%020.5i", -1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.0d", 1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.d", -1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.0i", 1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.i", -1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.u", 1024u);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.0u", -1024u);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.x", 0x1234abcdu);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.0x", -0x1234abcdu);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.X", 0x1234abcdu);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%20.0X", -0x1234abcdu);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%-175.96%%-153.x" ,822360617u);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.d", 1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.u", 1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.x", 0xee);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.X", 0xee);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%1.d", 1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%1.u", 1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%1.x", 0xee);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%1.X", 0xee);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%5.d", 1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%5.u", 1);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%5.x", 0xee);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%5.X", 0xee);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("-->|%-16.p|<-- ", NULL);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("-->|%-16.p|<-- ", NULL);
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
