/*
 输出三角形
 
    彭寒冰
    2019-4-3 21:20
*/

#include <iostream>
#include <string>
using namespace std;

#define WHOLE 1
#define LEFT  2
#define RIGHT 3

string str_rep(int n, string slice)
{
    string rep;
    for (int i = 0; i < n; i++)
        rep += slice;
    return rep;
}

int printTriangle(int shape, int layer = 5)
{
    switch (shape)
    {
    case WHOLE:
        for (int i = 1; i <= layer; i++)
            cout << string(2*(layer-i), ' ') << str_rep(2*i-1, "* ") << endl;
        break;
    case LEFT:
        for (int i = 1; i <= layer; i++)
            cout << string(2*(layer-i), ' ') << str_rep(i, "* ") << endl;
        break;
    case RIGHT:
        for (int i = 1; i <= layer; i++)
            cout << str_rep(i, "* ") << endl;
        break;
    default:
        return 0;
    }
    
    return 1;
}

int main()
{
    int choice;
    cout << "打印等腰三角形\n"
         << "[1]全部 [2]左半边 [3]右半边\n"
         << "请选择：";
    cin >> choice;
    printTriangle(choice);
    
    return 0;
}