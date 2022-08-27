#include <stdio.h>
#include <malloc.h>
#include "stack.h"

PNODE create_tree(void);
void traverse_tree(PNODE);

int main(void)
{
	PNODE pRoot = create_tree();
	return 0;
}

PNODE create_tree(void)
{
	int val;
	PSTACK pStack = createStack();
	PNODE pRoot = (PNODE)malloc( sizeof(NODE) );
	pRoot->pLchild = NULL;
	pRoot->pRchild = NULL;
	PNODE pNow = pRoot;



	printf("请输入节点的值：");
	scanf("%d", &(pRoot->data) );
	
	do
	{
		printf("1 创建左子结点；\n");
		printf("2 创建右子结点；\n");
		printf("3 转到左子结点；\n");
		printf("4 转到右子结点；\n");
		printf("5 返回父节点；");
		printf("0 停止创建。\n");
		printf("请选择：");
		scanf("%d", &val);
		switch (val)
		{
		case 1:
			if ( pNow->pLchild == NULL )
			{
				pNow->pLchild = (PNODE)malloc( sizeof(NODE) );

				pNow->pLchild->pLchild = NULL;
				pNow->pLchild->pRchild = NULL;

				printf("请输入节点的值：");
				scanf("%d", &(pNow->data) );
			}
			else
				printf("左子结点已存在！\n");
			break;
		
		case 2:
			if ( pNow->pRchild == NULL )
			{
				pNow->pRchild = (PNODE)malloc( sizeof(NODE) );

				pNow->pRchild->pLchild = NULL;
				pNow->pRchild->pRchild = NULL;

				printf("请输入节点的值：");
				scanf("%d", &(pNow->data) );
			}
			else
				printf("右子结点已存在！\n");
			break;
			
		case 3:
			if ( pNow->pLchild !=NULL )
			{
				push(pStack, pNow);
				pNow = pNow->pLchild;
			}
			else
				printf("左结点不存在！\n");
			break;
			
		case 4:
			if ( pNow->pRchild !=NULL )
			{
				push(pStack, pNow);
				pNow = pNow->pRchild;
			}
			else
				printf("右结点不存在！\n");
			break;
			
		case 5:
			pop(pStack, &pNow);
			break;
			
		case 0:
			break;
			
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	}while ( val!=0 );

	return pRoot;
}

void traverse_tree(PNODE pRoot)
{
	printf("%d", pRoot->data);
	
	if ( pRoot->pLchild != NULL )
		traverse_tree(pRoot->pLchild);
		
	if ( pRoot->pRchild 1= NULL )
		traverse_tree(pRoot->pRchild);
		
	return;
}