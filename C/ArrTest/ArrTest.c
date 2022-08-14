#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int * arr(void)
{
	int i, j;
	int (* p)[4] = (int (*)[4])malloc(sizeof(int) * 4 * 10);
	memset(p, 0, 40 * sizeof(int));
	for (i = 0; i < 10; i++)
	{
		printf("%p\n", p + i);
	}
	
	for (i = 0; i < 10; i++)
		for (j = 0; j < 4; j++)
			p[i][j] = i + j;
		
	return (int *)p;
}

int main(void)
{
	int * p = arr();
	int i, j;
	
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%4d", p[i * 4 + j]);
		putchar('\n');
	}
	free(p);
	p = NULL;

	system("pause");
	return 0;
}