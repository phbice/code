/*
 ��ӡ�纮ָ����
 
    ����
    2019-3-30 22:40
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//����纮ָ��
inline double windchill(double t, double v)
{
    return 35.74 + 0.6215*t + (-35.75 + 0.4275*t)*pow(v,0.16);
}

int main()
{
    double t, v; //�¶�(���϶�)�ͷ���(Ӣ��/Сʱ)
    
    cout << setw(7) << left << "  �¶�";
    for (t = -20; t <= 60; t += 10)
        cout << setw(8) << left << t;
    cout << "\n����\n" << string(79, '-') << endl;

    for (v = 0; v <= 50; v += 5)
    {
        cout << setw(7) << left << v;
        for (t = -20; t <= 60; t += 10)
            cout << setw(8) << left << setprecision(4) << windchill(t, v);
        cout << endl;
    }
    
    return 0;
}