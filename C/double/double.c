/************************************************
Input a double-precision floating-point number
and print it in binary format
	    by PHB 2018/2/10 14:52
************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int QWORD;

int print_double_information(double a);

int main(void)
{
	double a;
	char str[32];

	printf("Input a decimal number, and print out its information.\n");
	printf("Input \'q\' to quit the program.\n");
	do
	{
		printf("Input >");
		fgets(str, 32, stdin);
		if (strcmp(str, "q\n") == 0)
			break;
		a = atof(str);
		printf("\n----------------------------------------------------------------\n");
		print_double_information(a);
		printf("----------------------------------------------------------------\n\n");
	} while ( TRUE );
	return 0;
}

int print_double_information(double a)
{
	int i;
	char bits[64];

	QWORD mask;
	QWORD p;

	p = *((QWORD *)(&a));

	for (i = 63, mask = 0x8000000000000000LL; mask != 0; mask >>= 1, i--)
	{
		bits[i] = (p & mask) == 0 ? '0' : '1';
		putchar(bits[i]);
	}
	putchar('\n');

	printf("s:        %c\n", bits[63]);
	printf("exponent: ");
	for (i = 0; i < 11; i++)
	{
		putchar(bits[62 - i]);
	}
	printf("\nmantissa: ");
	for (i = 0; i < 52; i++)
	{
		putchar(bits[51 - i]);
	}
	putchar('\n');
	return 0;
}