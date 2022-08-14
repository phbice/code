/*
data structure: list
realize with array
2017-11-25 16:14:16
*/
#include <stdio.h>
#include <malloc.h>
#include "list.h"

LIST * creat(int n)
{
	LIST * pList = (LIST *)malloc( sizeof(LIST) + n*sizeof(ITEM) );
	if (pList != NULL)
	{
		pList->n = n;
		pList->i = 0;
	}
	return pList;
}

int append(LIST * pList, ITEM item)
{
	if (pList->i >= pList->n)
	{
		return FULL;
	}
	else
	{
		pList->item[pList->i] = item;
		pList->i++;
		return 0;
	}
}

ITEM get(LIST * pList, int i)
{
	if (i < pList->n)
	{
		return pList->item[i];
	}
}

void printlist(LIST * pList)
{
	int i;
	for (i=0; i<pList->i; i++)
	{
		printf("%lf ", get(pList, i));
	}
	putchar('\n');
}
