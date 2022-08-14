/*
 转换进制，使用递归
 
    彭寒冰
    2019-4-4 10:03
*/

#include <iostream>
using namespace std;

void baseConversion(int num, int base)
{
    if (num >= base)
    {
        baseConversion(num/base, base);
        cout << ' ' << num % base;
    }
    else
        cout << num;
}

int main()
{
    int n, base;
    cout << "转换进制，使用递归\n"
         << "请输入一个整数(十进制)和新的基数：";
    cin >> n >> base;
    
    baseConversion(n, base);
    cout << endl;
    
    return 0;
}