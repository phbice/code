#include <stdio.h>
#include <stdlib.h>

int oct2str(char *str, int oct);

int main()
{
    char str[15];
    oct2str(str, 0);
    printf(str);
    return 0;
}

/*
hex2str
    将整数以八进制转化为字符串
    参数：char *str -> 存放字符串的首地址
          int  oct  -> 要转换的整数
*/
int oct2str(char *str, int oct)
{
	int bit,NumBits;
	bit = '0' + (oct&0x07);   //oct % 8
	if (oct>>3 == 0)
	{
		str[0] = bit;
		str[1] = 0;
		return 1;
	}
	else
	{
		NumBits = oct2str(str, oct>>3);
		str[NumBits] = bit;
		str[NumBits + 1] = 0;
		return NumBits + 1;
	}
}
