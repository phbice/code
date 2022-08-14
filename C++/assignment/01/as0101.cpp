/*
 计算三角形面积
 
    彭寒冰
    2019-3-13 19:00
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c; // Sides of the triangle
    cout << "Input the sides of the triangle: ";
    cin >> a >> b >> c;
    cout << "Area of the triangle is "
         << sqrt((a+b+c)*(b+c-a)*(a+c-b)*(a+b-c))/4;
         
    return 0;
}