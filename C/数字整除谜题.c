/*
经典数字整除谜题：
用 1、2、3、4、5、6、7、8、9 组成一个九位数，使这个数：
前 1 位能被 1 整除
前 2 位能被 2 整除
前 3 位能被 3 整除
……
前 9 位能被 9 整除
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