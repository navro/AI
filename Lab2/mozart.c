
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bp()
{
	
}

struct {
	double				zero;
	int				i;
	char				s[7];
	char				t[7];
	unsigned long long		x;
	unsigned long long		y;
} a = { 0, 1756, "mozart\0", "???", 8243124871055238688ull };

size_t strlen(const char* s)
{
	int		i;
	
	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == 't')
			bp();	
		i++;
	}

	return i;
}
	
int main()
{
	int	length;

	strncpy(a.t, a.s, 6);
	
	length = strlen(a.t);

	printf("a.t is %s with length %d\n", a.t, length);

	return 0;
}
