/*
 ת�����ƣ�ʹ�õݹ�
 
    ����
    2019-4-4 10:03
*/

#include <iostream>
using namespace std;

void baseConversion(int num, int base)
{
    if (num >= base)
    {
        baseConversion(num/base, base);
        cout << ' ' << num % base;
    }
    else
        cout << num;
}

int main()
{
    int n, base;
    cout << "ת�����ƣ�ʹ�õݹ�\n"
         << "������һ������(ʮ����)���µĻ�����";
    cin >> n >> base;
    
    baseConversion(n, base);
    cout << endl;
    
    return 0;
}