/*
 ����Ͷ�ʷ�������ʱ��
 
    ����
    2019-3-30 23:14
*/

#include <iostream>
using namespace std;

int main()
{
    double rate; // ������
    double profit = 1; // ����
    int year = 0;
    cout << "����������(%)��";
    cin >> rate;
    rate /= 100;
    
    while (profit < 2)
    {
        profit *= 1 + rate;
        year ++;
    }
    
    cout << year << "���Ͷ�ʷ���" << profit << "��" << endl;
    return 0;
}