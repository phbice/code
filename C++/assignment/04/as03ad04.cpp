/*
 ���������Ϸ
 ��ʾһ�����֣�һ�����ʧ��֮�����Ҫ�����⴮���֣�
 ÿ�ι��أ�����ʾ������һ�����֡�
 ��󣬵÷� = ��Դ���*100/��������
 
    ����
    2019-3-31 16:03
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void xsleep(unsigned int milliseconds)
{
    clock_t t0 = clock();
    while (clock() - t0 <= (double)milliseconds/1000. * CLOCKS_PER_SEC);
    return;
}

string rand_num_str(unsigned int length)
{
    string num_str;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < length; i++)
        num_str.append(1, rand()%10 + '0');
    return num_str;
}

int main()
{
    string num_str;
    string input;
    int str_length = 3, right_count = 0;
    clock_t t0;
    double dt;

    cout << "                ���������Ϸ\n"
         << "    ��Ϸ�����У���Ļ�Ͻ���ʾһ�����֣�һ�����ʧ��\n"
         << "֮����Ҫ���ݼ��������⴮���֡�������ȷ���������\n"
         << "�����������ֹ��ÿ������������ֳ������ӡ�����\n"
         << "�÷��ǣ���Դ���*100/�ش���ʱ��\n"
         << "׼���ú�";
    system("pause");
    system("cls");

    while (true)
    {
        system("cls");

        //��ʾ�����һ���Ӳ�����
        num_str = rand_num_str(str_length);
        cout << num_str;
        xsleep(1000);
        system("cls");

        //�ȴ�������벢��ʱ
        t0 = clock();
        cout << "�����룺";
        cin >> input;
        dt += (double)(clock() - t0) / CLOCKS_PER_SEC;

        if (input == num_str) // �ش���ȷ
        {
            cout << "��ȷ��";
            xsleep(500);

            right_count++;

            if (right_count % 3 == 0) // ÿ���3�ξ����ӳ���
            {
                system("cls");
                cout << "�������ӣ�����׼��...";
                xsleep(2000);

                str_length++;
            }
        }
        else // �ش����
        {
            cout << "�Ǵ��ˣ���ȷ�����" << num_str << "\n"
                 << "�ܹ����" << right_count << "�Σ�"
                 << "��ʱ" << dt << "�룬"
                 << "�ܷ�" << right_count*100 / dt << "\n"
                 << "����һ�Σ�[y/n] ";
            cin >> input;
            if (input == "y")
            {
                str_length = 3;
                right_count = 0;
                dt = 0;
            }
            else
                break;
        }
    }
}