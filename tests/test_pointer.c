/*Test "p" flag without bonus*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *s, ...);

void test_p_flag(int (*f)(const char *s, ...), void *p, void *pp)
{
	int return_value;

	return_value = f("%p", p);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("&%p&", p);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("&%p&%p", p, pp);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%p%p%p%p%p", p, p, p, p, p);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%p/%p?%p*%p0%p", p, p, p, p, pp);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%p/%p?%p*%p0%p", NULL, p, pp, p, pp);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%p%p%p%p%p", NULL, NULL, p, p, p);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%p%p%p%p%p", NULL, NULL, p, p, p);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%p%p%p%p%p", 0x7ffc5183bfc01337, NULL, 0, p, p);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%p%p%p%p%p", 0x7ffc5183bfc01337, NULL, 0, -1, p);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%p%p%p%p%p$", 0x7ffc5183bfc01337, NULL, 0, -1, p);
	printf("\nReturn value: [%d]\n", return_value);
	return_value = f("%p%p%p%p%p$$", 0x7ffc5183bfc01337, NULL, 0, -1, p);
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
		test_p_flag(printf, (void *)0x7ffc5183bfc0, (void *)0x7ffdb8616ca0);
	else if (strcmp(av[1], "you") == 0)
		test_p_flag(ft_printf, (void *)0x7ffc5183bfc0, (void *)0x7ffdb8616ca0);
	else
		printf("Unkown flag\n");
}
