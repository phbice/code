#include <stdio.h>

int main()
{
    int ch;

    while ((ch = getchar()) != '#')
        putchar(ch);

    return 0;
}
