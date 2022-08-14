/**
list
*/
#include <stdio.h>
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
	list->iEnd = 0;
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
	list->iEnd = 0;
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

int copylist(LIST * dest, LIST * src)
{
	NODE * pNode;
	emptylist(dest);
	for (pNode = first(src); pNode != NULL; pNode = advance(pNode))
	{
		append(dest, retrieve(pNode));
	}
	return 0;
}

LIST * splitlist(LIST * scrList, NODE * pSplitNode)
{
	int iPrevEnd = scrList->iEnd;
	NODE * travNode; //Node used to travel through the list
	NODE * prevNode = previous(scrList, pSplitNode); // previous node of the split point

	LIST * newList  = createlist();

		//new list is splited from the previous list
	newList->header->pNext = pSplitNode; 

		// break the link of the two lists
	prevNode->pNext = NULL;
		
		//reset pointer to the ending node
	newList->pEnd = scrList->pEnd; 
	scrList->pEnd = prevNode;     

		//count the number of nodes in new lists
	for (travNode = scrList->header, scrList->iEnd = 0; advance(travNode) != NULL; travNode = advance(travNode), scrList->iEnd++);
	newList->iEnd = iPrevEnd - scrList->iEnd;

	return newList;
}

int catlist(LIST * base, LIST * ext)
{
	base->pEnd->pNext = ext->header->pNext;
	base->pEnd = ext->pEnd;
	base->iEnd += ext->iEnd;
	free(ext->header);
	free(ext);
	return 0;
}

int listlen(LIST * list)
{
	return list->iEnd;
}

NODE * first(LIST * list)
{
	return list->header->pNext;
}

NODE * last(LIST * list)
{
	return list->pEnd;
}

NODE * previous(LIST * list, NODE * pNode)
{
	NODE * prevNode = first(list);
	for (; (prevNode != NULL) && (advance(prevNode) != pNode); prevNode = advance(prevNode));

	return prevNode;
}

NODE * advance(NODE * pNode)
{
	return pNode->pNext;
}

NODE * getkth(LIST * list, int k)
{
	int count;
	NODE * travNode;
	for (travNode = list->header, count = 0; (travNode != NULL) && (count < k); travNode = advance(travNode), count++);
	return travNode;
}

ITEM * retrieve(NODE * pNode)
{
	return &(pNode->item);
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

static void printitem(ITEM * pItem, int flag)
{
	if (flag == 1)
	{
		switch (pItem->degree)
		{
		case 0:
			printf("%.2lf ", pItem->coef);
			break;

		case 1:
			printf("%.2lfx ", pItem->coef);
			break;
		default:
			printf("%.2lf*x^%d ", pItem->coef, pItem->degree);
		}
	}
	else
	{
		if (pItem->degree == 1)
			printf("%+.2lf*x ", pItem->coef);
		else
			printf("%+.2lf*x^%d ", pItem->coef, pItem->degree);
	}
	return;
}

void printlist(LIST * list)
{
	NODE * pNode;
	pNode = first(list);
	printitem(retrieve(pNode), 1);
	pNode = advance(pNode);
	while ( pNode != NULL )
	{
		printitem(retrieve(pNode), 0);
		pNode = advance(pNode);
	}
}