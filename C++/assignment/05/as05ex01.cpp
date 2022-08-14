/*
 将整数反转输出，使用递归
 
    彭寒冰
    2019-4-4 09:57
*/

#include <iostream>
using namespace std;

void reverse(int n)
{
    if (n >= 10)
    {
        cout << n % 10;
        reverse(n / 10);
    }
    else
        cout << n;
    return;
}

int main()
{
    int n;
    
    cout << "将整数反转输出，使用递归\n"
         << "请输入一个整数：";
    cin >> n;
    
    reverse(n);
    cout << endl;
    
    return 0;
}