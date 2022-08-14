#define _UNICODE

#include <stdio.h>
#include <tchar.h>

int main(void)
{
    TCHAR a[] = __TEXT("你好！");
    _tprintf(a);

    return 0;
}
