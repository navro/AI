#include <stdio.h>

int main(int argc, char* argv[])
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	printf("Please enter two numbers: ");

	scanf("%u %u", &a, &b);

	c = a + b;

	printf("%u %u = %u\n", a, b, c);

	return 0;
}
