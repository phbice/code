/*
���������������⣺
�� 1��2��3��4��5��6��7��8��9 ���һ����λ����ʹ�������
ǰ 1 λ�ܱ� 1 ����
ǰ 2 λ�ܱ� 2 ����
ǰ 3 λ�ܱ� 3 ����
����
ǰ 9 λ�ܱ� 9 ����
*/

#include <stdio.h>
#include <malloc.h>

int traverseNum(void);
int isNum(int);

int main(void)
{

	return 0;
}

int isNum(int num)
{
	int i,j,temp;
	for (i=1,j=9; i<10; i++,j--)
	{
		temp = (int)( num/i )
		if ( temp%j != 0 )
			break;
	}
	if ( i==10 )
		return 1;
	else
		return 0;
}

int traverseNum(void)
{
	int i;
	for (i=100000000; i<=999999999; i++)
		if (isNum(i))
			printf("%d", i);
}