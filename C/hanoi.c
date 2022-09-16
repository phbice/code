# include <stdio.h>

void solveHanoi(int, char, char, char);

int main (void)
{
	int n;

	printf("解决汉诺塔\n");
	printf("输入盘片的个数：\n");
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