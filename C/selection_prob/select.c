#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#define MAX_LEN 100000

int find_k(int *, int, int);
int my_select(int Input[], int InputSize, int k);
void insert(int * input, int len, int element, int pos);

clock_t ticks;

int main(void)
{
	int i;
	int len = MAX_LEN/1000;
	int * input = (int *)malloc(MAX_LEN*sizeof(int));

	FILE * pRandom = fopen("random","rb");

//	for (; len<=MAX_LEN; len+=MAX_LEN/100)
//	{
		fread(input, sizeof(int), len, pRandom);
		for (i = 0; i < len; i++)
		{
			printf("%d\n", input[i]);
		}
//		my_select(input, len, len/2);
		printf("\n%d\n", find_k(input, len, len / 2));
		printf("%d\n", ticks);
		printf("%d\n", my_select(input, len, len / 2));
//	}

	fclose(pRandom);
	free(input);

	system("pause");
	return 0;
}

int my_select(int Input[], int InputSize, int k)
{
	int i, j, k_cur;
	int result; //Store the result

	int * pK = (int *)malloc((k+1) * sizeof(int));
	

	if (pK==NULL)
	{
		perror("Memory alloc failed!\n");
		exit(1);
	}

	
	ticks = clock();
	
	for (i=0, k_cur=1, pK[0]=Input[0]; i<InputSize; i++)
	{
		for (j=0; Input[i] < pK[j] && j<k_cur; j++);
		
		if(Input[i] > pK[j])
		{
			insert(pK, k_cur+1, Input[i], j);
			k_cur = (k_cur+1>k ? k : k_cur+1);
		}
	}

	result = pK[k - 1];
	
	ticks = clock()-ticks;
	free(pK);
	return result;
}

void insert(int * input, int len, int element, int pos)
{
	int i;
	for (i=len-2; i>=pos; i--)
		input[i+1] = input[i];
		
	input[pos] = element;
	return;
}
