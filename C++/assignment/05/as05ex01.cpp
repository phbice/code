/*
 ��������ת�����ʹ�õݹ�
 
    ����
    2019-4-4 09:57
*/

#include <iostream>
using namespace std;

void reverse(int n)
{
    if (n >= 10)
    {
        cout << n % 10;
        reverse(n / 10);
    }
    else
        cout << n;
    return;
}

int main()
{
    int n;
    
    cout << "��������ת�����ʹ�õݹ�\n"
         << "������һ��������";
    cin >> n;
    
    reverse(n);
    cout << endl;
    
    return 0;
}