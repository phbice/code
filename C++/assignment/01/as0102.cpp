/*
 ���պؿ�

    ����
    2019-3-13 19:58
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string my_name, others_name;
    cout << "����������֣�";
    getline(cin, my_name);
    cout << "������˵����֣�";
    getline(cin, others_name);
    
    for (int i = 0; i < 8; i++)
        cout << "---***";
    cout << endl;
    cout << others_name << "��\n    ף�����տ��֣�" << endl;
    cout << setw(6*8) << setfill(' ')
         << "������ѣ�" + my_name << endl; // Align right
    for (int i = 0; i < 8; i++)
        cout << "---***";
    cout << endl;
    return 0;
}
