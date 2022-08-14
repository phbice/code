#include <stdio.h>

typedef double POWER_BASE;

POWER_BASE power(POWER_BASE a, unsigned int n);

int main(void)
{
	POWER_BASE a;
	unsigned int n;
	scanf("%lf %ud", &a, &n);
	printf("%lf", power(a,n));
	return 0;
}

POWER_BASE power(POWER_BASE a, unsigned int n)
{
	POWER_BASE remain = 1;
	
	if (n == 0)
	{
		return 1;
	}
	else
	{
		while (n >= 2)
		{
			remain *= ( (n&1)==1 ? a : 1 );
			a      *= a;
			n = n >> 1;
		}
		return a * remain;
	}
}
