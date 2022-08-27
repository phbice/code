#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int PerfectSquareQ(unsigned int a)
{
    unsigned int    sqrta      = 0, //square root of a
                    parta      = 0, //two bits in a
                    trya       = 0,
                    remainder  = 0, 
                    mask       = 0xC0000000,
                    partnum    = 16;
    while(partnum != 0)
    {
        parta = ( (a&mask) >> (2*(partnum - 1)) ) | (remainder<<2);
        trya  = (sqrta << 2) | 1;
        if (parta >= trya )
        {
            sqrta = (sqrta << 1) | 1;
            remainder = parta - trya;
        }
        else
        {
            sqrta = sqrta << 1;
            remainder = parta;
        }
        mask = mask >> 2;
        partnum --;
    }

    if (remainder == 0)
        return TRUE;
    else
        return FALSE;
}

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
    int a = str2num( argv[1] );
    printf("%d\n", PerfectSquareQ(a));
    return 0;
}
