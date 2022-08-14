/*
 计算周工资

    彭寒冰
    2019-3-30 10:13
*/

#include <iostream>

using namespace std;

int main()
{
    double hours, hourly_wage;
    cout << "请输入工作小时数和时薪：";
    cin >> hours >> hourly_wage;
    if (hours < 0 || hourly_wage < 0)
        cout << "输入有误：工作小时数和时薪不得为负数" << endl;
    else if (hours <= 40)
        cout << "总工资为：" << hours * hourly_wage << endl;
    else
        cout << "总工资为：" << 40 * hourly_wage + (hours - 40) * hourly_wage * 1.5 <<endl;

    return 0;
}