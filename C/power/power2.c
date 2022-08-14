# include <stdio.h>

int power(int, int);



int main(void)
{

	int a, n;

	scanf_s("%d %d", &a, &n);

	printf("%d\n", power(a, n));



	system("pause");

	return 0;

}

int power(int a, int n)
{

	int I;

	int p = a;

	for (I = 0; ; I++)
	{
		if (n >> I == 1)
			break;
	}

	for (; I > 0; I--)
	{

		if ((n >> (I - 1)) % 2 == 0)

			p = p * p;

		else

			p = p * p * a;

	}

	return p;
}
