#include <stdio.h>

int hex2str(char *str, int hex)
{
	char table[16] = {'0','1','2','3','4','5','6','7',
			  '8','9','A','B','C','D','E','F'};
	int bit,NumBits;

	bit = hex & 0x0F;
	if (hex>>4 == 0)
	{
		str[0] = table[bit];
		str[1] = 0;
		return 1;
	}
	else
	{
		NumBits = hex2str(str, hex>>4);
		str[NumBits] = table[bit];
		str[NumBits+1] = 0;
		return NumBits + 1;
	}
}

int main(void)
{
	char string[9];
	hex2str(string, 0);
	printf(string);
	printf("\n");
	return 0;
}
