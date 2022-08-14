/*
 计算投资翻倍所需时间
 
    彭寒冰
    2019-3-30 23:14
*/

#include <iostream>
using namespace std;

int main()
{
    double rate; // 年利率
    double profit = 1; // 收益
    int year = 0;
    cout << "输入年利率(%)：";
    cin >> rate;
    rate /= 100;
    
    while (profit < 2)
    {
        profit *= 1 + rate;
        year ++;
    }
    
    cout << year << "年后，投资翻了" << profit << "倍" << endl;
    return 0;
}