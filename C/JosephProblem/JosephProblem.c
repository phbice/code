#include <stdio.h>
#include <stdlib.h>

#define NODESIZE sizeof(NODE)

typedef struct node {
	int data;
	struct node *next;
}NODE;

NODE * CreateLoopList(int n)
{
	int i;
	NODE * pHeader;
	NODE * pTail = NULL;
	NODE * pNewNode;

	pHeader = (NODE*)malloc(NODESIZE);
	pHeader->data = 1;
	pHeader->next = NULL;
	
	
	pTail = pHeader;
	for (i = 2; i <= n; i++)
	{
		pNewNode = (NODE *)malloc(NODESIZE);
		pNewNode->data = i;
		pNewNode->next = NULL;

		pTail->next = pNewNode;
		pTail = pNewNode;
	}
	
	pTail->next = pHeader;
	return pHeader;
}

//Get next node
NODE * Advance(NODE * pNode)
{
	return pNode->next;
}

//Get previous node
NODE * Previous(NODE * pNode)
{
	NODE * pPrevNode;
	for (pPrevNode = pNode; Advance(pPrevNode) != pNode; pPrevNode = Advance(pPrevNode));

	return pPrevNode;
}

//Get the date of a node
int Retrieve(NODE * pNode)
{
	return pNode->data;
}

void joseph(NODE * list, int n)
{
	static int ceilingList[100];
	int ceiling;
	int i;
	int index; //Idex number of every people
//	int w;
	NODE *pNode, *pPrevNode, *pDropedNode;

	printf("密码为：\n");
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &ceilingList[i]);
	
	}

	printf("m的初值是:\n");
	scanf_s("%d", &ceiling);

	pNode = list;
	while (n>1)
	{
		for (i = 1; i < ceiling; i++)
			pNode = Advance(pNode);

		index = Retrieve(pNode);
		ceiling = ceilingList[index];

		pDropedNode = pNode;
		pPrevNode = Previous(pNode);
		pPrevNode->next = pNode->next;
		pNode = pNode->next;
		free(pDropedNode);

		printf("跳出的为%d号\n", index);
		n--;
	}
	printf("跳出的为%d号\n", Retrieve(pNode));
}

int main()
{
	NODE *head;
	int n;

	printf("总人数为：\n");
	scanf_s("%d",&n);

	head = CreateLoopList(n);
	joseph(head,n);

	system("pause");
}

