/*
 �����ľ���
 
    ����
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
    cout << "��������Բ�ĵĺ��������Բ��һ��ĺ������꣺";
    cin >> x_c >> y_c >> x >> y;
    
    radius = distance(x_c, y_c, x, y);
    
    cout << "�뾶��" << radius
         << "ֱ����" << 2*radius
         << "�ܳ���" << 2*PI*radius
         << "�����" << PI*radius*radius << endl;

    return 0;
}