/*
 �����ܹ���

    ����
    2019-3-30 10:13
*/

#include <iostream>

using namespace std;

int main()
{
    double hours, hourly_wage;
    cout << "�����빤��Сʱ����ʱн��";
    cin >> hours >> hourly_wage;
    if (hours < 0 || hourly_wage < 0)
        cout << "�������󣺹���Сʱ����ʱн����Ϊ����" << endl;
    else if (hours <= 40)
        cout << "�ܹ���Ϊ��" << hours * hourly_wage << endl;
    else
        cout << "�ܹ���Ϊ��" << 40 * hourly_wage + (hours - 40) * hourly_wage * 1.5 <<endl;

    return 0;
}