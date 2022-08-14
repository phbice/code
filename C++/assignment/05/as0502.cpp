/*
 两点间的距离
 
    彭寒冰
    2019-4-3 21:07
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793238462643;

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    double x_c, y_c, x, y, radius;
    cout << "依次输入圆心的横纵坐标和圆上一点的横纵坐标：";
    cin >> x_c >> y_c >> x >> y;
    
    radius = distance(x_c, y_c, x, y);
    
    cout << "半径：" << radius
         << "直径：" << 2*radius
         << "周长：" << 2*PI*radius
         << "面积：" << PI*radius*radius << endl;

    return 0;
}