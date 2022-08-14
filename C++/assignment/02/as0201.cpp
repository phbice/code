/*
 计算三角形的周长和面积
 
    彭寒冰
    2019-3-22 15:07
*/
#include <iostream>
#include <cmath>

using namespace std;

bool istriangle(double a, double b, double c)
{
    return a>0&&b>0&&c>0 && fabs(a-b)<c&&c<a+b;
}

int main()
{
    double a, b, c; // Sides of the triangle
    cout << "输入三角形的三边长：";
    cin >> a >> b >> c;
    
    if ( !istriangle(a, b, c) )
        cout << "无法构成三角形！" << endl;
    else
        cout << "边长：" << a + b + c << endl
             << "面积：" << sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a))/4 << endl;

    return 0;
}