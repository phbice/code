#include <stdio.h>
#include <malloc.h>

typedef struct CirculatingDecimal
{
	int infinity;
	int start;
	int end;
	int data[];
}CD;

CD * Fraction2CirculatingDecimal(int numerator, int denominator);

int main(void)
{
	int a,b,i;
	CD * pDecimal;
	scanf("%d",&a);
	scanf("%d",&b);
	pDecimal = Fraction2CirculatingDecimal(a,b);
	printf("%d/%d = %d.", a, b, pDecimal->data[0]);
	for (i=1; i<=pDecimal->end; i++)
	{
		if ( (i == pDecimal->start) && (pDecimal->infinity == 1) )
		{
			putchar('(');
		}

		printf("%d",pDecimal->data[i]);
	}
	if (pDecimal->infinity == 1)
	{
		putchar(')');
	}
	putchar('\n');
	return 0;
}

CD * Fraction2CirculatingDecimal(int numerator, int denominator)
{
	unsigned int i,             //loop counter
	             reminder = 0 ;
	CD         * pDecimal           =         (CD *)malloc(sizeof(CD) + sizeof(int) * (denominator));
	signed int * ReminderPosition   = (signed int *)malloc(sizeof(int) * denominator);
	
	for (i=0; i<denominator; i++)
	{
		pDecimal->data[i]   = -1;
		ReminderPosition[i] = -1;
	}
	pDecimal->infinity = 1;
	
	i = 0;
	while(1)
	{
		pDecimal->data[i] = numerator/denominator;
		reminder = numerator%denominator;
		numerator = reminder*10;
		if (reminder == 0)
		{
			pDecimal->infinity = 0;
			break;
		}
		if (ReminderPosition[reminder] != -1)
		{
			break;
		}
		i++;
		ReminderPosition[reminder] = i;
	}
	pDecimal->start = ReminderPosition[reminder];
	pDecimal->end   = i;
	return pDecimal;
}
