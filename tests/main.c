#include "../ft_printf.h"
#include <stdio.h>


void	test_case(char *format, void *add)
{
	int	ret_t;
	int	ret;
	ret_t = printf(format, add);
	ret = ft_printf(format, add);
	printf("|%d ----%d|\n", ret_t, ret);
	printf("\n-----\n");
}

void	test_str(char *format, char *str)
{
	int	ret_t;
	int	ret;
	ret_t = printf(format, str);
	ret = ft_printf(format, str);
	printf("|%d ----%d|\n", ret_t, ret);
	printf("\n-----\n");
}

int main(void)
{
	int	a;
	

	printf("|%+120p|\n", &a);
	return (0);
}
