/*
 ���ȵ�λ����
 ����(km)  Ӣ��(mi)    
 ��(m)     Ӣ��(ft)
 ����(cm)  Ӣ��(in)
 
    ����
    2019-3-22 15:06
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    double input_length;
    string unit_flag;
    cout << "Input length end with unit flag[km/m/cm/mi/ft/in]: ";
    cin >> input_length >> unit_flag;
    
    if (unit_flag == "km")
        cout << input_length * 0.621382 << "mi" << endl;
    else if (unit_flag == "mi")
        cout << input_length * 1.609344 << "km" << endl;
    else if (unit_flag == "m")
        cout << input_length * 3.28089 << "ft" << endl;
    else if (unit_flag == "ft")
        cout << input_length * 0.304794 << "m" << endl;
    else if (unit_flag == "cm")
        cout << input_length * 0.393707 << "in" << endl;
    else if (unit_flag == "in")
        cout << input_length * 2.53995 << "cm" << endl;
    else
        cout << "Unknown unit flag" << endl;

    return 0;
}