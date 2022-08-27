#ifndef _STACK_H
#define _STACK_H

#include "tree.h"

typedef struct StackNode
{
	NODE data;
	struct StackNode * pNext;
}STACKNODE, * PSTACKNODE;

typedef struct Stack
{
	PSTACKNODE pTop;		//pTopָ��ջ��
	PSTACKNODE pBottom;	//pBottomָ��ջ��
}STACK, * PSTACK;

extern PSTACK createStack(void);
extern int push(PSTACK, int);
extern int pop(PSTACK, int *);

#endif