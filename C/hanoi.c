# include <stdio.h>

void solveHanoi(int, char, char, char);

int main (void)
{
	int n;

	printf("�����ŵ��\n");
	printf("������Ƭ�ĸ�����\n");
	scanf("%d", &n);
	solveHanoi(n, A, B, C);

	return 0;
}

void solveHanoi(int n, char from, char transit, char to);
{
	if (n == 1)
		printf("%c -> %c", from, to);
	else
	{
		solveHanoi(n-1, from, to, transit);
		printf("%c -> %c", from, to);
		solveHanoi(n-1, transit, from, to);
	}
}