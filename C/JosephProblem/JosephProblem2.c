#include <stdio.h>
#include <stdlib.h>
#define len sizeof(node)
typedef struct node {
	int data;
	struct node *next;
}node;
node *create()
{
	int n;
	int i;
	int b;
	node *head, *p, *q, *tail = 0;
	printf("总人数为:\n");
	scanf_s("%d", &n);
	head = (node*)malloc(len);
	p = (node*)malloc(len);

	head->data = 1;
	p = head;


	for (i = 1;i < n;i++)
	{
		q = (node*)malloc(len);
		p->next = q;
		b = i + 1;
	    q->data=b;
		p = q;
		tail = p;

	}

	tail->next = head;
	return(head);
}


void joseph(node*head)
{
	int m;
	int n = 7;
	int a;
	int b;
	int c;
	int code[100];
	node *p, *q;
	printf("密码为：\n");
	for (c = 1;c < n;c++)
	{
		scanf_s("%d", &code[c - 1]);

	}
	printf("m的值为:\n");
	scanf_s("%d", &m);
	printf("m的值为：%d\n", m);
	


	p = head;
	while (n)
	{
		for (a = 1;a < ((m) % n);a++)
		{
			q = p;
			p = p->next;
		}
	
		q->next = p->next;
		b = p->data;

		printf("出列的为%d\n", b);
		m = code[b - 1];
		free(p);
		p = q->next;
	
		n--;



	}
}
int main()
{
	node *head;
	
	head = create();
	
	joseph(head);
	system("pause");
}


