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
	PSTACKNODE pTop;		//pTop指向栈顶
	PSTACKNODE pBottom;	//pBottom指向栈底
}STACK, * PSTACK;

extern PSTACK createStack(void);
extern int push(PSTACK, int);
extern int pop(PSTACK, int *);

#endif