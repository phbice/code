/* find the k-th max largest number
2017-12-16 21:52:10
*/

#include <stdio.h>

#define N 128
#define BUFFER_SIZE 32

int get(char szString[], int * pData);
int IsNumber(char c);

int main(void)
{
	static int iNumber[N];
	static char cBuffer[N];
	int i, j;
	int iNumAvailable;

	fflush(stdin);
	
	printf("Input integer(s) one per line, end with an empty line.\n");
	for (i=0; i<N; i++)
	{
		printf("Input No.%-3d>",i+1);
		gets(cBuffer);
		if (cBuffer[0] == 0)
			break;
		
		if ( cBuffer[ get(cBuffer, &iNumber[i]) ] )
		{
			printf("\nPlease do not input non-numeric character\n\n");
			i--;
		}
	}
	iNumAvailable = i;
	
	printf("The integer(s) you have input:");
	for (i=0; i<iNumAvailable; i++)
	{
		if (i%5 == 0)
		{
			putchar('\n');
		}
		printf("%-10d",iNumber[i]);
	}
	
	return 0;
}

int get(char szString[], int * pData)
{
	int i;
	for (i=0, *pData=0; IsNumber(szString[i]); i++)
	{
		*pData = (*pData)*10 + szString[i]-'0';
	}
	return i;
}

int IsNumber(char c)
{
	if ( ('0'<=c) && (c<='9') )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

