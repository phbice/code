#include "stdio.h"

int str2num(char * p_str)
{
	int i;
	int n = 0;
	for (i=0; p_str[i]!=0; i++)
	{
		n = 10*n + p_str[i]-'0';
	}
	return n;
}

int main(int argc, char * argv[])
{
	int n;           //input number
	int factor = 2;
	int r;           //remainder
	int i;           //loop counter

	if (argc == 1)
	{
		printf("no number input\n");
		return 0;
	}

	for (i=1; i<argc; i++)
	{
		n = str2num(argv[i]);
		printf("%d: ",n);
		while (factor<n)
		{
			r = n % factor; //try possible factor one by one
			if (r == 0)     //remainder == 0 means a factor
			{
				printf("%d ",factor);
				n = n/factor;
				factor = 2;
				continue;
			}
			factor++;
		}
		printf("%d\n",n);
	}

	return 0;
}
