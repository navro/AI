#include <stdio.h>

#define N (1000)

int	a[N] = { 1, 2, 3, 4, };
int     x = 1000;

int main()
{
	int	i;	
	int	sum;

	for (i = 0; i <= N; i++)
		a[i] = 0;

	printf("x = %d\n", x);
	return 0;
}
