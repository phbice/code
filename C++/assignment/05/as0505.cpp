/*
 �þ��η��󶨻���
 
    ����
    2019-4-3 22:03
*/

#include <iostream>
using namespace std;

double integrate(double (*f)(double), double a, double b, unsigned int slice_num = 10000)
{
    double result = 0;
    
    for (int i = 0; i < slice_num; i++)
        result += f(a + (b-a)/slice_num*i) * (b-a)/slice_num;
    
    return result;
}

double f(double x)
{
    return x * (x + 1);
}

int main()
{
    double a, b;
    cout << "���η����㶨����\n"
         << "����������f(x) = (1 + x) * x\n"
         << "�������������Ķ˵� a b (a<b)��";
    cin >> a >> b;
    
    cout << integrate(f, a, b) << endl;
    
    return 0;
}