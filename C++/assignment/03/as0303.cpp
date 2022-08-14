/*
 求和：sum = a + aa + aaa + aaaa + aa...a (n个a)
 a是一位数字
 
    彭寒冰
    2019-3-30 22:31
*/

#include <iostream>
using namespace std;

int main()
{
    int a, n, a_n;
    int sum = 0;
    
    cout << "求和：sum = a + aa + aaa + aaaa + aa...a (n个a)\n"
         << "请输入 a 和 n ：";
    cin >> a >> n;
    
    a_n = a;
    for (int i = 0; i < n; i++)
    {
        sum += a_n;
        a_n = a_n * 10 + a;
    }
    
    cout << "sum = " << sum << endl;
    
    return 0;
}