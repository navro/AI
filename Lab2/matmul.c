#if 0
#define N 		(16)
#else
#define N 		(1024)
#endif

float a[N][N];
float b[N][N];
float c[N][N];

void mm()
{
	int	i, j, k;

	for (i = 0; i < N; i += 1) {
		for (j = 0; j < N; j += 1) {
			a[i][j] = 0.0;
			for (k = 0; k < N; k += 1) {
				a[i][j] += b[i][k] * c[k][j];
			}
		}
	}
}

int main()
{
	mm();

	return 0;
}
