# include <stdio.h>
# include <malloc.h>

void g(int * pArr, int * pArrNew,int m, int n, int length)
{
	int i,j;
	j = 1;
	for (i = 0; i<length; i++)
	{
		if (i != m && i != n)
		{
			pArrNew[j] = pArr[i];
			j++;
		}
	}
	return;
}

int f(int * pArr,int length)
{
	int i, j = 0;
//	int t=pArr[length-2];
	int * pArrNew = (int *)malloc(4*(length-1));

	if ( length >= 3 )
	{
		for (i=0; i<length; i++)
		{
			for (j=0; j<i; j++)
			{
///////////////////////////////////////////////////////
				pArrNew[0] = pArr[i] + pArr[j];
				g(pArr, pArrNew, i, j, length);
				switch ( f(pArrNew,length-1) )
				{
				case 1:
					result[length-1] = 
				}

				/*if (f(pArrNew,length-1) !=0)
				{
					free(pArrNew);
					return 1;
				}
*/
				pArrNew[0] = pArr[i] - pArr[j];
				g(pArr, pArrNew, i, j, length);
				if (f(pArrNew,length-1) !=0)
				{
					free(pArrNew);
					return 1;
				}

				pArrNew[0] = pArr[j] - pArr[i];
				g(pArr, pArrNew, i, j, length);
				if (f(pArrNew,length-1) !=0)
				{
					free(pArrNew);
					return 1;
				}

				pArrNew[0] = pArr[i] * pArr[j];
				g(pArr, pArrNew, i, j, length);
				if (f(pArrNew,length-1) !=0)
				{
					free(pArrNew);
					return 1;
				}

				if (pArr[j] != 0)
				{
					pArrNew[0] = pArr[i] / pArr[j];
					g(pArr, pArrNew, i, j, length);
					if (f(pArrNew,length-1) !=0)
					{
						free(pArrNew);
						return 1;
					}
				}

				if (pArr[i] != 0)
				{
					pArrNew[0] = pArr[j] / pArr[i];
					g(pArr, pArrNew, i, j, length);
					if (f(pArrNew,length-1) !=0)
					{
						free(pArrNew);
						return 1;
					}
				}
////////////////////////////////////////////////////////////
			}
		}
		return 0;
	} 
	else if (length ==2)
	{
		if (pArr[0] + pArr[1] == 24)
			return 1;
		else if (pArr[0] - pArr[1] == 24)
			return 2;
		else if (pArr[1] - pArr[0] == 24)
			return 3;
		else if (pArr[0] * pArr[1] == 24)
			return 4;
		else if (pArr[1] != 0 && pArr[0] / pArr[1] == 24)
			return 5;
		else if (pArr[0] != 0 && pArr[1] / pArr[0] == 24)
			return 6;
		else
			return 0;
	}
	else
		return 0;
}

int main(void)
{
	int * pArr = (int *)malloc(4*4);
	pArr[0]=4;
	pArr[1]=2;
	pArr[2]=3;
	pArr[3]=5;
	printf("%d\n",f(pArr,4));
	return 0;
}