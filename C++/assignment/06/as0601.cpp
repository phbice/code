/*
 航空订票程序
 
    彭寒冰
    2019-4-29 20:50
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int FIRST_CLASS = 0;
const int ECONOMY_CLASS = 1;
const int NO_SEAT = -1;
const string seat_class_str[2] = {"头等舱", "经济舱"};

#define SWITCH_CLASS(seat_class) (1-(seat_class))

int ticket_man(int seat_class)
{
    static int seats[20] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};
    
    int seat_begin, seat_end;
    
    if (seat_class == FIRST_CLASS)
    {
        seat_begin = 0;
        seat_end = 5;
    }
    else
    {
        seat_begin = 5;
        seat_end = 20;
    }
    
    for (int i = seat_begin; i < seat_end; i++)
        if (seats[i] == 0)
        {
            seats[i] = 1;
            return i+1;
        }
    return NO_SEAT;
}

int menu()
{
    string input;

    while (true)
    {
        cout << "订票系统\n"
             << "[1] 头等舱\n"
             << "[2] 经济舱\n"
             << "请选择[1/2]：";
        getline(cin, input);

        if (input == "1")
            return FIRST_CLASS;
        else if (input == "2")
            return ECONOMY_CLASS;
        else
            cout << "输入有误，情重新输入[1/2]：";
    }

    return -1;
}

int main()
{
    string input;
    int seat_class, seat_num;

    while (true)
    {
        system("cls");

        seat_class = menu();
        seat_num = ticket_man(seat_class);

        if (seat_num == NO_SEAT)
        {
            cout << seat_class_str[seat_class] + "已满，是否选择" +
            seat_class_str[SWITCH_CLASS(seat_class)] + "？[y/n]：";
            getline(cin, input);
            if (input == "y")
            {
                seat_class = SWITCH_CLASS(seat_class);
                seat_num = ticket_man(seat_class);
            }
        }
        
        if (seat_num != NO_SEAT)
        {
            cout << "登机牌：\n";
            cout << string(30, '*') << "\n";
            cout << string(12, ' ') << seat_class_str[seat_class] << "\n";
            cout << string(10, ' ') << "座位号：" << seat_num << "\n";
            cout << string(30, '*') << endl;
        }
        else if (input == "y" && seat_num == NO_SEAT)
            cout << "票已售罄，下一班飞机将在3小时后起飞。" << endl;
        else if (input == "n")
            cout << "下一班飞机将在3小时后起飞。" << endl;

        cout << "按[Enter]返回菜单";
        cin.get();
    }

    return 0;
}