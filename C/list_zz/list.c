#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2
#define ERROR 0
#define OK 1 
typedef int Status;
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode * next;
}LinkNode;
LinkNode* CreatList(LinkNode *, int*, int);
LinkNode* reverse(LinkNode *);
int main()
{
	LinkNode * l = NULL;
	int n, i;
	printf("输入一个链表的长度\n");
	scanf("%d", &n);
	int*a = (int *)malloc(n * sizeof(int));
	printf("采用头插法，逆序输入一个链表\n");
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	l = CreatList(l, a, n);
	l = reverse(l);
		printf("将该单链表原地逆置为\n");
	for (i = 0; i<n; i++)
	{
		printf("%d ", l->data);
		l = l->next;
	}
	putchar('\n');
	system("pause");
	return 0;
}
LinkNode* CreatList(LinkNode *l, int *a, int n)
{
	LinkNode *s;
	int i;
	l = (LinkNode *)malloc(sizeof(LinkNode));
	l->next = NULL;
	for (i = 0; i<n; i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = l->next;
		/*指针域的赋值*/
		l->next = s;
	}
	return l;
}
LinkNode* reverse(LinkNode *l)
/*单链表的就地逆置,采用递归*/
{
	LinkNode *newl;
	/*构造一个新结点当做头结点*/
	if (l == NULL || l->next == NULL)
		return l;
	newl = reverse(l->next);
	l->next->next = l;
	/*反向的操作*/
	l->next = NULL;
	return newl;
}