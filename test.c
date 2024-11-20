#include <stdio.h>


struct tests {
	int	x;
	char	i;
	double y;
	char s[10];
};

int main()
{
	printf("%d\n", sizeof(struct tests));
}
