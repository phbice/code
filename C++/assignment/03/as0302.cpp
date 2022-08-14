/*
 计算人民币组合情况和组合数
 
    彭寒冰
    2019-3-30 22:03
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int N; //人民币总数
    int n2, n5; //2元、5元纸币数量
    int comb_count = 0; //组合数

    cout << "输入人民币总数N(元) [1 <= N <= 1000]：";
    cin >> N;
    
    if (N < 0 || 1000 < N)
    {
        cout << "输入的N超出范围！" << endl;
        return 1;
    }

    cout << '\n';
    cout << setw(10) << left << "一元纸币"
         << setw(10) << left << "二元纸币"
         << "五元纸币\n" << string(28, '-') << endl;

    for (n2 = 1; 2*n2 < N; n2++)
        for (n5 = 1; 2*n2 + 5*n5 < N; n5++)
        {
            comb_count++;
            cout << setw(10) << left << N - 2*n2 - 5*n5
                 << setw(10) << left << n2
                 << n5 << endl;
        }
    cout << "共" << comb_count << "种组合方式。" << endl;
    
    return 0;
}