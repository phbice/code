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
	printf("������Ϊ:\n");
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
	printf("����Ϊ��\n");
	for (c = 1;c < n;c++)
	{
		scanf_s("%d", &code[c - 1]);

	}
	printf("m��ֵΪ:\n");
	scanf_s("%d", &m);
	printf("m��ֵΪ��%d\n", m);
	


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

		printf("���е�Ϊ%d\n", b);
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


