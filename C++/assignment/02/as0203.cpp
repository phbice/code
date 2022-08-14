/*
 计算BMI
 
    彭寒冰
    2019-3-30 11:06
*/

#include <iostream>
using namespace std;

int main()
{
    double bmi, weight, height;
    cout << "请输入身高(m)和体重(kg)：";
    cin >> height >> weight;
    bmi = weight / height / height;
    
    cout << "BMI = " << bmi << "  身体状况：";
    if (bmi < 18.5)
        cout << "过轻" << endl;
    else if (bmi < 23.9)
        cout << "正常" << endl;
    else if (bmi < 27)
        cout << "过重" << endl;
    else if (bmi < 32)
        cout << "肥胖" << endl;
    else
        cout << "非常肥胖" << endl;

    return 0;
}