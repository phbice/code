/*
 记忆测试游戏
 显示一串数字，一秒后消失，之后玩家要输入这串数字；
 每次过关，会显示更长的一串数字。
 最后，得分 = 答对次数*100/所用秒数
 
    彭寒冰
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

    cout << "                记忆测试游戏\n"
         << "    游戏过程中，屏幕上将显示一串数字，一秒后消失，\n"
         << "之后你要根据记忆输入这串数字。输入正确，则继续；\n"
         << "输入错误，则终止。每答对三次则数字长度增加。最终\n"
         << "得分是：答对次数*100/回答用时。\n"
         << "准备好后，";
    system("pause");
    system("cls");

    while (true)
    {
        system("cls");

        //显示随机数一秒钟并清屏
        num_str = rand_num_str(str_length);
        cout << num_str;
        xsleep(1000);
        system("cls");

        //等待玩家输入并计时
        t0 = clock();
        cout << "请输入：";
        cin >> input;
        dt += (double)(clock() - t0) / CLOCKS_PER_SEC;

        if (input == num_str) // 回答正确
        {
            cout << "正确！";
            xsleep(500);

            right_count++;

            if (right_count % 3 == 0) // 每答对3次就增加长度
            {
                system("cls");
                cout << "长度增加，做好准备...";
                xsleep(2000);

                str_length++;
            }
        }
        else // 回答错误
        {
            cout << "记错了！正确结果：" << num_str << "\n"
                 << "总共答对" << right_count << "次，"
                 << "用时" << dt << "秒，"
                 << "总分" << right_count*100 / dt << "\n"
                 << "再来一次？[y/n] ";
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