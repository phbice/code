/*
 求分数序列 2/1, 3/2, 5/3, 8/5, 13/8, 21/13, ... 的前30项之和

    彭寒冰
    2019-3-30 21:51
*/

#include <iostream>
using namespace std;

int main()
{
    int f1 = 1, f2 = 2, t;
    double sum = 0;
    for (int i = 0; i < 30; i++)
    {
        sum += (double)f2 / (double)f1;
        t = f2;
        f2 += f1;
        f1 = t;
    }
    
    cout << sum;
    
    return 0;
}