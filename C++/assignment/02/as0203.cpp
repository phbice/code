/*
 ����BMI
 
    ����
    2019-3-30 11:06
*/

#include <iostream>
using namespace std;

int main()
{
    double bmi, weight, height;
    cout << "���������(m)������(kg)��";
    cin >> height >> weight;
    bmi = weight / height / height;
    
    cout << "BMI = " << bmi << "  ����״����";
    if (bmi < 18.5)
        cout << "����" << endl;
    else if (bmi < 23.9)
        cout << "����" << endl;
    else if (bmi < 27)
        cout << "����" << endl;
    else if (bmi < 32)
        cout << "����" << endl;
    else
        cout << "�ǳ�����" << endl;

    return 0;
}