#include <stdio.h>

signed long long f(signed long long n)
{
	if (n < 1)
		return n;
	else
		return n * f(n-1);
}

int main()
{
	printf("%lld\n", f(20));
	return 0;
}
