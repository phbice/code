#ifndef _TREE_H
#define _TREE_H

typedef struct Node
{
	int data;
	struct Node * pLchild;
	struct Node * pRchild;
}NODE, * PNODE;

#endif