#include<stdio.h>
#include<malloc.h>

typedef struct Stack
{
	int pTop;
	int pNow;
	int * Array;
//	int isFull;
}STACK, * PSTACK;

PSTACK creatStack(int size)
{
	PSTACK pStack;
	int * Array;
	if (size <= 0)
		return NULL;

	Array = (int *)malloc( size*sizeof(int) );
	pStack = (PSTACK)malloc( sizeof(STACK) );
	pStack -> pTop = 0;
	pStack -> pNow = 0;
	pStack -> Array = Array;
}

int full(PSTACK pStack)
{
	if (pStack -> pNow == pTop)
		return 1;
	else
		return 0;
}

int empty(PSTACK pStack)
{
	if (pStack -> pNow == 0)
		return 1;
	else
		return 0;
}

int push(PSTACK pStack, int data)
{
	if ( full(pStack) )
		return 1;
	else
	{
		pStack -> pNow = pStack -> pNow + 1;
		pStack -> Array[pStack -> pNow] = data;
		return 0;
	}
}

int pop(PSTACK pStack, int * data)
{
	if ( empty(pStack) )
		return 1;
	else
	{
		*data = pStack -> Array[pStack -> pNow];
		pStack -> pNow = pStack -> pNow - 1;
		return 0;
	}
}