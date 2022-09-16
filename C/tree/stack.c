# include <stdio.h>
# include <malloc.h>
# include "stack.h"

PSTACK createStack(void)//����ջ
{
	PSTACK pStack = (PSTACK)malloc( sizeof(STACK) );
	pStack->pBottom = pStack->pTop = (PSTACKNODE)malloc( sizeof(STACKNODE) );
	pStack->pBottom->pNext = NULL;

	return pStack;
}

int push(PSTACK pStack, NODE data)//ѹջ���ɹ�����true��ʧ�ܷ���false
{
	PSTACKNODE pNew = (PSTACKNODE)malloc( sizeof(STACKNODE) );
	if (pNew==NULL)
		return 0;

	pNew->data = data;
	pNew->pNext = pStack->pTop;
	pStack->pTop = pNew;

	return 1;
}

int pop(PSTACK pStack, PNODE data)//��ջ���ɹ�����true��ʧ�ܷ���false
{
	if (pStack->pBottom == pStack->pTop)
		return 0;

	PSTACKNODE pTemp;

	*data = pStack->pTop->data;
	pTemp = pStack->pTop;
	pStack->pTop = pStack->pTop->pNext;
	free(pTemp);

	return 1;
}