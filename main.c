#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int r;
	char long_string[1000];
	ft_memset(long_string, 'a', 999);
	long_string[999] = '\0';
	int return_value = ft_printf("%s", NULL);
	printf("\nReturn value: [%d]\n", return_value);

}
