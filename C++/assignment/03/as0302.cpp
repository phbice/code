/*
 ����������������������
 
    ����
    2019-3-30 22:03
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int N; //���������
    int n2, n5; //2Ԫ��5Ԫֽ������
    int comb_count = 0; //�����

    cout << "�������������N(Ԫ) [1 <= N <= 1000]��";
    cin >> N;
    
    if (N < 0 || 1000 < N)
    {
        cout << "�����N������Χ��" << endl;
        return 1;
    }

    cout << '\n';
    cout << setw(10) << left << "һԪֽ��"
         << setw(10) << left << "��Ԫֽ��"
         << "��Ԫֽ��\n" << string(28, '-') << endl;

    for (n2 = 1; 2*n2 < N; n2++)
        for (n5 = 1; 2*n2 + 5*n5 < N; n5++)
        {
            comb_count++;
            cout << setw(10) << left << N - 2*n2 - 5*n5
                 << setw(10) << left << n2
                 << n5 << endl;
        }
    cout << "��" << comb_count << "����Ϸ�ʽ��" << endl;
    
    return 0;
}