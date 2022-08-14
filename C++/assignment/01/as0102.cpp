/*
 生日贺卡

    彭寒冰
    2019-3-13 19:58
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string my_name, others_name;
    cout << "输入你的名字：";
    getline(cin, my_name);
    cout << "输入别人的名字：";
    getline(cin, others_name);
    
    for (int i = 0; i < 8; i++)
        cout << "---***";
    cout << endl;
    cout << others_name << "：\n    祝你生日快乐！" << endl;
    cout << setw(6*8) << setfill(' ')
         << "你的朋友：" + my_name << endl; // Align right
    for (int i = 0; i < 8; i++)
        cout << "---***";
    cout << endl;
    return 0;
}
