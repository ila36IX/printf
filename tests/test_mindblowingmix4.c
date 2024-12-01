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
	return_value = f("%.10d", -42);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("pp %.50d\n", 10000);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p2 %.10s\n", "cccc");
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p8 %.10d\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p9 %.50d\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p16 %.10i\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p17 %.50i\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p24 %.10x\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p25 %.50x\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p32 %.10u\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("p33 %.50u\n", 100);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.20s", "Hallo heimur");
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.20d", 1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.20d", -1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.20i", 1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.20i", -1024);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.20u", 1024u);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.20u", -1024u);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.20x", 0x1234abcdu);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%.20x", -0x1234abcdu);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%00054.91x%-119.117s%.120s%-3.12X" ,2341589136u,"V0dP#8kjTEcV7&k(cX>QVDa","oUyFMC$9``PRmEAG|~@|`<^'Q@",198320040u);
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
