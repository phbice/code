//x[n+1] = x[n] + x[n]^2/n^2

#include <stdio.h>

int main(void)
{
	int a[4][4] = { { 1, 0, 0, 0 },
		            { 1, 1, 0, 0 },
				    { 0, 0, 1, 1 },
					{ 0, 0, 1, 1 }};
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j<4; j++)
		{
			printf("%d",a[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
