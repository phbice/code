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



	printf("������ڵ��ֵ��");
	scanf("%d", &(pRoot->data) );
	
	do
	{
		printf("1 �������ӽ�㣻\n");
		printf("2 �������ӽ�㣻\n");
		printf("3 ת�����ӽ�㣻\n");
		printf("4 ת�����ӽ�㣻\n");
		printf("5 ���ظ��ڵ㣻");
		printf("0 ֹͣ������\n");
		printf("��ѡ��");
		scanf("%d", &val);
		switch (val)
		{
		case 1:
			if ( pNow->pLchild == NULL )
			{
				pNow->pLchild = (PNODE)malloc( sizeof(NODE) );

				pNow->pLchild->pLchild = NULL;
				pNow->pLchild->pRchild = NULL;

				printf("������ڵ��ֵ��");
				scanf("%d", &(pNow->data) );
			}
			else
				printf("���ӽ���Ѵ��ڣ�\n");
			break;
		
		case 2:
			if ( pNow->pRchild == NULL )
			{
				pNow->pRchild = (PNODE)malloc( sizeof(NODE) );

				pNow->pRchild->pLchild = NULL;
				pNow->pRchild->pRchild = NULL;

				printf("������ڵ��ֵ��");
				scanf("%d", &(pNow->data) );
			}
			else
				printf("���ӽ���Ѵ��ڣ�\n");
			break;
			
		case 3:
			if ( pNow->pLchild !=NULL )
			{
				push(pStack, pNow);
				pNow = pNow->pLchild;
			}
			else
				printf("���㲻���ڣ�\n");
			break;
			
		case 4:
			if ( pNow->pRchild !=NULL )
			{
				push(pStack, pNow);
				pNow = pNow->pRchild;
			}
			else
				printf("�ҽ�㲻���ڣ�\n");
			break;
			
		case 5:
			pop(pStack, &pNow);
			break;
			
		case 0:
			break;
			
		default:
			printf("����������������룡\n");
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