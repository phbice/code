/*
 ���������ε��ܳ������
 
    ����
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
    cout << "���������ε����߳���";
    cin >> a >> b >> c;
    
    if ( !istriangle(a, b, c) )
        cout << "�޷����������Σ�" << endl;
    else
        cout << "�߳���" << a + b + c << endl
             << "�����" << sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a))/4 << endl;

    return 0;
}