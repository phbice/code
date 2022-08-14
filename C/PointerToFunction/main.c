#include <stdio.h>

int sum(int a1, int d, int n)
{
    return a1*n + n*(n-1)*d/2;
}

int main()
{
    int (*f)(int a1, int d, int n);
    f = sum;
    printf("%d",f(1,1,100));
    return 0;
}
