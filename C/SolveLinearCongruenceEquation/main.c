// Solve a*n === b (mod m)

#include <stdio.h>

int main(void)
{
    int a = 24,
        b = 1,
        m = 13,
        k = 1;
    if ( a >= m )
    {
        a = a % m;
        b = b % m;
    }

    while (a != 1)
    {
        k = (m / a) + 1;
        a = a * k - m;
        b = (b * k) % m;
    }
    printf("%d",b);
}
