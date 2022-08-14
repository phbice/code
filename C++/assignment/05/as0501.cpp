/*
 ��e^x�Ľ���ֵ
 
    ����
    2019-3-31 17:21
*/

#include <iostream>
using namespace std;

double exp(double x)
{
    double result = 0, xn = 1;
    
    for (int i = 1; xn > 1E-6 || result * xn > 1E-6; i++)
    {
        result += xn;
        xn = xn * x / i;
    }
    result += xn;
    
    return result;
}

int main()
{
    double x;
    
    cout << "����e^x, ����1E-6��\n";
    cout << "������ x : ";
    cin >> x;
    
    cout << "e^" << x << " = " << exp(x) << endl;
    
    return 0;
}
