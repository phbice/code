/*
 �Ƚϴ�С����������
 
    ����
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

    cout << "���С������ʹ�ú�������\n"
         << "����������ʵ����";
    cin >> a >> b;
    cout << "��С������ " << min(a, b) << endl;
    
    cout << "����������������";
    cin >> c >> d;
    cout << "��С������ " << min(c, d) << endl;
    
    return 0;
}