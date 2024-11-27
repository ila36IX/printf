/*Test "x" flag without bonus*/
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

	return_value = f("%x", 1337);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x%x", -1, -1337);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x%x", UINT_MAX, 0);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x%x", (long)UINT_MAX + 1337, (long)INT_MIN - 1337);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x%x%x%x%x", 0, 10, 100, 10000, 100000);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x", 99999999999999999);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x/%x/%x/%x", -999999, 'a', 'l', 'i');
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x%x%x%x%x%x%x%x%x%x", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x/%x+%x", 0, UINT_MAX, UINT_MAX/2);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x %x %x %x", 
		  (unsigned char)255,
		  (unsigned short)65535,
		  (unsigned long)4294967295UL,
		  (unsigned long long)18446744073709551615ULL
		  );
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x %x %x %x", 
		  (unsigned int)-1,
		  (unsigned int)-42,
		  (unsigned int)(-UINT_MAX),
		  (unsigned int)(-123456)
		  );
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x %x %x %x", 
		  UINT_MAX + 1,
		  (unsigned int)(-42),
		  (long)ULONG_MAX,
		  (unsigned long long)ULLONG_MAX
		  );
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x%x%x%x%x%x", 0, 0, 0, 42, 42, 42);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x %x %x", 0xFFFFFFFF, 010, 0b11111111);
	printf("\nReturn value: [%x]\n", return_value);

	return_value = f("%x %x %x", (unsigned int)3.14, (unsigned int)-2.718, (unsigned int)0.0);
	printf("\nReturn value: [%x]\n", return_value);

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
