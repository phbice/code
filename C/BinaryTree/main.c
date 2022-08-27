#include <stdio.h>
#include <stdlib.h>

#define BELOW       -1
#define EQUAL        0
#define ABOVE        1

typedef int ITEM;

typedef struct sNode
{
    ITEM sItem;
    struct sNode * pLeft;
    struct sNode * pRight;
}NODE;

NODE * InitTree(void)
{
    NODE *p = malloc(sizeof(NODE));
    if (p != NULL)
    {
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}

int Cmp(ITEM *pItem1, ITEM *pItem2)
{
    if (*pItem1 > *pItem2)
    {
        return ABOVE;
    }
    else if (*pItem1 == *pItem2)
    {
        return BELOW;
    }
    else
    {
        return EQUAL;
    }
}

ITEM * SearchItem(NODE *pRoot, ITEM *pItem)
{
    NODE *pNode = pRoot;
    int CmpResult;

    while ( pNode!=NULL )
    {
        CmpResult = Cmp(pItem, &(pNode->sItem));
        if (CmpResult == EQUAL)
        {
            return &(pNode->sItem);
        }
        else if (CmpResult == ABOVE)
        {
            pNode = pNode->pRight;
        }
        else if (CmpResult == BELOW)
        {
            pNode = pNode->pLeft;
        }
    }
    return NULL;
}

int AddItem(NODE *pRoot, ITEM *pItem)
{

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
