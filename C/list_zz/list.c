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
	printf("����һ������ĳ���\n");
	scanf("%d", &n);
	int*a = (int *)malloc(n * sizeof(int));
	printf("����ͷ�巨����������һ������\n");
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	l = CreatList(l, a, n);
	l = reverse(l);
		printf("���õ�����ԭ������Ϊ\n");
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
		/*ָ����ĸ�ֵ*/
		l->next = s;
	}
	return l;
}
LinkNode* reverse(LinkNode *l)
/*������ľ͵�����,���õݹ�*/
{
	LinkNode *newl;
	/*����һ���½�㵱��ͷ���*/
	if (l == NULL || l->next == NULL)
		return l;
	newl = reverse(l->next);
	l->next->next = l;
	/*����Ĳ���*/
	l->next = NULL;
	return newl;
}