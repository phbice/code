#include <stdio.h>
#include <stdlib.h>
#define NO_ENOUGH_RAM 1
#define EMPTY 2
typedef struct Node
{
    int Data;
    struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack
{
    PNODE pBottom;
    PNODE pTop;
}STACK, * PSTACK;

PSTACK creatStack(void)
{
    PNODE pBottom = (PNODE)malloc(sizeof(NODE));  //Bottom node of the stack
    PSTACK pStack = (PSTACK)malloc(sizeof(STACK));//args of the stack
    if ((pBottom==NULL)||(pStack==NULL))
        return NULL;

    pBottom -> pNext   = NULL;
    pStack  -> pBottom = pBottom;
    pStack  -> pTop    = pBottom;
    return pStack;
}

int push(PSTACK pStack,int data)
{
    PNODE pNode = (PNODE)malloc(sizeof(NODE));
    if ( pNode == NULL )
        return NO_ENOUGH_RAM;

    pNode -> Data  = data;
    pNode -> pNext = pStack->pTop;
    pStack-> pTop  = pNode;
    return 0;
}

int pop(PSTACK pStack,int * data)
{
    PNODE pNode    = pStack -> pTop;
    if(pNode -> pNext  ==  NULL)
        return EMPTY;
    *data          = pNode  -> Data;
    pStack -> pTop = pNode  -> pNext;
    free(pNode);
    return 0;
}

int main(void)
{
    int a,data;

    PSTACK pStack = creatStack();
    if (pStack == NULL)
    {
        printf("Error:No enough RAM");
        return 1;
    }

    do
    {
        printf("\n1>push\n2>pop\n3>quit");
        putchar('\n');
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            scanf("%d",&data);
            if(push(pStack, data) == NO_ENOUGH_RAM)
                printf("\nError:No enough RAM\n");
            break;
        case 2:
            if(pop(pStack, &data) == EMPTY)
                printf("\nError:The stack is empty\n");
            else
                printf("%d\n", data);
            break;
        }
    }while(a != 3);

    return 0;
}
