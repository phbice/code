/*
 ���ն�Ʊ����
 
    ����
    2019-4-29 20:50
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int FIRST_CLASS = 0;
const int ECONOMY_CLASS = 1;
const int NO_SEAT = -1;
const string seat_class_str[2] = {"ͷ�Ȳ�", "���ò�"};

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
        cout << "��Ʊϵͳ\n"
             << "[1] ͷ�Ȳ�\n"
             << "[2] ���ò�\n"
             << "��ѡ��[1/2]��";
        getline(cin, input);

        if (input == "1")
            return FIRST_CLASS;
        else if (input == "2")
            return ECONOMY_CLASS;
        else
            cout << "������������������[1/2]��";
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
            cout << seat_class_str[seat_class] + "�������Ƿ�ѡ��" +
            seat_class_str[SWITCH_CLASS(seat_class)] + "��[y/n]��";
            getline(cin, input);
            if (input == "y")
            {
                seat_class = SWITCH_CLASS(seat_class);
                seat_num = ticket_man(seat_class);
            }
        }
        
        if (seat_num != NO_SEAT)
        {
            cout << "�ǻ��ƣ�\n";
            cout << string(30, '*') << "\n";
            cout << string(12, ' ') << seat_class_str[seat_class] << "\n";
            cout << string(10, ' ') << "��λ�ţ�" << seat_num << "\n";
            cout << string(30, '*') << endl;
        }
        else if (input == "y" && seat_num == NO_SEAT)
            cout << "Ʊ����������һ��ɻ�����3Сʱ����ɡ�" << endl;
        else if (input == "n")
            cout << "��һ��ɻ�����3Сʱ����ɡ�" << endl;

        cout << "��[Enter]���ز˵�";
        cin.get();
    }

    return 0;
}