#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern clock_t ticks;

int find_k(int *, int, int);
/*
int main()
{
    int i;
    int *num = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
        scanf("%d", &num[i]);
    
    printf("%d\n", find_k(num, N, K));
    return 0;
}
*/
int find_k(int *num, int n, int k)
{
    int i, j;
    char *b = (char *)malloc(sizeof(char) * 0x100000000);

	ticks = clock();

	memset(b, 0, 0x100000000);
    for(i = 0; i < n; i++)
    {
        b[(unsigned long int)num[i] + 0x7FFFFFFL] = 1;
    }
    for (i = 0, j = 0;; i++)
    {
        if (b[i] == 1)
            j++;
        if (j == k)
            break;
    }
	ticks = clock() - ticks;

	free(b);
    return i - 0x7ffffff;
}


