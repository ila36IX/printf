#include "main.h"
#include <stdio.h>
int main(void)

{
	int a,b;

	_printf("-- My printf --\n");
	a = _printf("Should print a single percent sign: %%\n");


	_printf("-- Thier ptintf --\n");
	b = _printf("Should print a single percent sign: %%\n");

	printf("-My printf return: %i\n-Thier printf return:%i\n", a , b);
	return 0;
}

