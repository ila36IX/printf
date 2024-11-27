#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <stdint.h>

int main()
{
	printf("UINTPTR_MAX as pointer: %p\n", (void*)UINTPTR_MAX);
	ft_printf("UINTPTR_MAX as pointer: %p\n", (void*)UINTPTR_MAX);
}
