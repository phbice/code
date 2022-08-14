// sqrt by bit operation
// 2017/4/30 16:44 PHB

#include <stdio.h>
#include <stdlib.h>

int sqrt(unsigned int a)
{
    unsigned int    sqrta  = 0,
                    parta  = 0,
                    resta  = 0,
                    trya   = 0,
                    mask   = 0xC0000000,
                    bitnum = 16;
    while(bitnum != 0)
    {
        parta = ( (a&mask) >> 2*(bitnum - 1) ) | (resta<<2);
        trya  = (sqrta << 2) | 1;
        if (parta >= trya)
        {
            sqrta = (sqrta << 1) | 1;
            resta = parta - trya;
        }
        else
        {
            sqrta = sqrta << 1;
            resta = parta;
        }
        mask = mask >> 2;
        bitnum --;
    }
    return sqrta;
}

int main(void)
{
    unsigned int a = 1 << 29;
    printf("%d", sqrt(a));
    return 0;
}

/*
input  2^29
output 23170
*/
