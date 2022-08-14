/**
list
*/
#include <stdlib.h>
#include <string.h>

#include "list.h"

LIST * createlist()
{
	NODE * header;
	LIST * list = (LIST *)malloc(sizeof(LIST));
	if (list == NULL)
		return NULL;
	
	header = (NODE *)malloc(sizeof(NODE));
	if (header == NULL)
		return NULL;

	list->header = header;
	list->iNow = 0;
	list->iEnd = 0;
	list->pNow = header;
	list->pEnd = header;
	header->pNext = NULL;
	return list;
}

int emptylist(LIST * list)
{
	NODE * pStart = list->header->pNext;
	while (pStart!=NULL)
	{
		list->header->pNext = pStart->pNext;
		free(pStart);
		pStart = list->header->pNext;
	}
	list->iNow = 0;
	list->iEnd = 0;
	list->pNow = list->header;
	list->pEnd = list->header;
	return 0;
}

int destroylist(LIST * list)
{
	emptylist(list);
	free(list->header);
	free(list);
	return 0;
}

int setlistpos(LIST * list, int pos, int offset)
{
	int i;
	switch (pos)
	{
	case LIST_NOW:
		list->iNow += offset;
		for (i=0; i<offset; i++)
			list->pNow = list->pNow->pNext;
		break;

	case LIST_START:
		list->iNow = 1 + offset;
		for (i=0, list->pNow=list->header; i<list->iNow; i++)
			list->pNow = list->pNow->pNext;
		break;
	}
	return 0;
}

int getitem(LIST * list, ITEM * item)
{
	if (list->pNow == NULL)
		return 1;
	memcpy(item, &(list->pNow->item), sizeof(ITEM));
	list->iNow++;
	list->pNow = list->pNow->pNext;
	return 0;
	
}

int append(LIST * list, ITEM * item)
{
	list->pEnd->pNext = (NODE *)malloc(sizeof(NODE));
	if (list->pEnd->pNext == NULL)
		return 1;
	else
	{
		list->pEnd = list->pEnd->pNext;
		memcpy(&(list->pEnd->item), item, sizeof(ITEM));
		list->pEnd->pNext = NULL;
		list->iEnd++;
	}
	return 0;
}

int push(LIST * stack, ITEM * item)
{
	NODE * newnode = (NODE *)malloc(sizeof(NODE));
	if (newnode == NULL)
		return 1;

	memcpy(&(newnode->item), item, sizeof(ITEM));
	newnode->pNext = stack->header->pNext;
	stack->header->pNext = newnode;
	return 0;
}

int pop(LIST * stack, ITEM * item)
{
	NODE * popeditem;
	if (stack->header->pNext == NULL)
		return 1;

	memcpy(item, &(stack->header->pNext->item), sizeof(ITEM));
	popeditem = stack->header->pNext;
	stack->header->pNext = stack->header->pNext->pNext;
	free(popeditem);

	return 0;
}

int top(LIST * stack, ITEM * item)
{
	if (stack->header->pNext == NULL)
		return 1;

	memcpy(item, &(stack->header->pNext->item), sizeof(ITEM));
	return 0;
}

int isempty(LIST * stack)
{
	return stack->header->pNext == NULL;
}

void printlist(LIST * list)
{
	ITEM tempitem;
	setlistpos(list, LIST_START, 0);
	while (!getitem(list, &tempitem))
	{
		printitem(&tempitem);
	}
}