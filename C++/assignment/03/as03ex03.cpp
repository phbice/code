/*
 输出 Syracuse序列 (3X+1问题中的序列)
 
    彭寒冰
    2019-3-30 23:24
*/

#include <iostream>
using namespace std;

inline int syr(int x)
{
    return x%2 == 0 ? x/2 : 3*x+1;
}

int main()
{
    int x;
    cout << "Syracuse序列生成器\n";
    cout << "请输入起始值(正整数)：";
    cin >> x;
    
    cout << x;
    while (x != 1)
    {
        x = syr(x);
        cout << ", " << x;
    }
    
    return 0;
}