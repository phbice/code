/*
 ��� Syracuse���� (3X+1�����е�����)
 
    ����
    2019-3-30 23:24
*/

#include <iostream>
using namespace std;

inline int syr(int x)
{
    return x%2 == 0 ? x/2 : 3*x+1;
}

int main()
{
    int x;
    cout << "Syracuse����������\n";
    cout << "��������ʼֵ(������)��";
    cin >> x;
    
    cout << x;
    while (x != 1)
    {
        x = syr(x);
        cout << ", " << x;
    }
    
    return 0;
}