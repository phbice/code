//Add b to a by bit operation instead of plus sign.

#include <stdio.h>

int main(void)
{
    int a = 1223, b = 3221, //addend
        carry;
    while ( b != 0 )
    {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    printf("%d", a);
    return 0;
}

//output: 4444
