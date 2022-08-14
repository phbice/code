/*
 比较大小，函数重载
 
    彭寒冰
    2019-4-3 21:54
*/

#include <iostream>
using namespace std;

int min(int a, int b)
{
    return a<b ? a : b;
}

double min(double a, double b)
{
    return a<b ? a : b;
}

int main()
{
    double a, b;
    int c, d;

    cout << "求较小的数，使用函数重载\n"
         << "请输入两个实数：";
    cin >> a >> b;
    cout << "较小的数是 " << min(a, b) << endl;
    
    cout << "请输入两个整数：";
    cin >> c >> d;
    cout << "较小的数是 " << min(c, d) << endl;
    
    return 0;
}