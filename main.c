#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <stdint.h>

int main()
{
	printf("->%-8.4d\n", 13370);
	ft_printf("=>%-8.4d\n", 13370);
	// f("%11d", INT_MIN);

}
