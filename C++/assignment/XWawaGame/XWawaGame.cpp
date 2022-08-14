/*
	《C++程序设计》课程实验作业：结构化程序设计和基于对象编程练习
	程序：瓦瓦捡豆游戏
	任务：为瓦瓦分配不同的任务，然后设计瓦瓦捡豆的最优路径算法，并编写程序代码，执行程序验证结果

	创 建 人：Zhang Hua
	创建时间：2011-02-20

	修改记录：
	2019-03-01 修改遗留的C风格代码。
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
using namespace std;

#include "XWawa.h"

#define VS2017 // 如果你用的不是VS2010，就把VS2010改成你所用的IDE的名称，例如VS2017，DEVCPP

#ifdef VS2010
	#pragma comment(lib, "XWawa.lib")
#else
	#ifdef VS2017
		#pragma comment(lib, "XWawa_VS2017.lib")
	#else
		#pragma comment(lib, "XWawa.a")
	#endif
#endif

void BEGIN();
void END(XWawa&);

void jump(XWawa & wawa);
void wawa_task_0(XWawa & wawa);
void wawa_task_1(XWawa & wawa);
void wawa_task_2_3_4(XWawa & wawa);

int menu();

int main()
{
	XWawa wawa;
	int task_num;

	SetConsoleTitle("Wawa Game");

	while (true)
	{
		// menu函数，展示菜单，与用户交互，获取输入
		task_num = menu();
		if (task_num == 5)
			break;
		wawa.assignTask(task_num);

		// 提示按下任意键后开始执行后面的指令（完成任务的算法实现）
		BEGIN();

		// ----------------------指令开始----------------------------

		switch (task_num)
		{
		case 0:
			wawa_task_0(wawa);
			break;
		case 1:
			wawa_task_1(wawa);
			break;
		case 2:
		case 3:
		case 4:
			wawa_task_2_3_4(wawa);
			break;
		}

		// ----------------------指令结束----------------------------

		// 检查上面的指令执行后是否完成了任务，并给出相应的提示
		END(wawa);
	}
	
	return 0;
}

void wawa_task_0(XWawa &wawa)
{
	wawa.moveUp();
	wawa.moveUp();
	while (wawa.beanIsHere())
	{
		wawa.pickupBean();
		if (wawa.rightIsClear())
			wawa.moveRight();
		else
			break;
	}
}

void wawa_task_1(XWawa &wawa)
{
	wawa.moveRight();
	wawa.pickupBean();
	while (wawa.upsideIsClear())
	{
		wawa.moveUp();
		wawa.moveRight();
		wawa.pickupBean();
	}
	while (wawa.downsideIsClear())
	{
		wawa.moveDown();
		wawa.moveRight();
		wawa.pickupBean();
	}
}

void wawa_task_2_3_4(XWawa &wawa)
{
	while (wawa.rightIsClear())
	{
		wawa.moveRight();
		wawa.pickupBean();
	}
	while (!wawa.taskIsAccomplished())
	{
		jump(wawa);
		wawa.pickupBean();
		while (wawa.rightIsClear())
		{
			wawa.moveRight();
			wawa.pickupBean();
		}
	}
}

void jump(XWawa & wawa)
{
	while (!wawa.beanIsHere())
	{
		while (!wawa.rightIsClear())
			wawa.moveUp();
		wawa.moveRight();
		while (wawa.rightIsClear() && !wawa.downsideIsClear())
			wawa.moveRight();
		while (wawa.downsideIsClear())
			wawa.moveDown();
	}	
}


void BEGIN()
{
	cout<<"\n按[Enter]键后开始执行指令";
	char c = cin.get();
}

void END(XWawa &wawa)
{
	cout<<"\n指令已执行，正在检查任务完成情况......\n";
	if (wawa.taskIsAccomplished())
	{
		cout<<"\n恭喜！任务已完成。瓦瓦移动了"<<wawa.GetMoveCount()<<"次。\n";
	}
	else
	{
		cout<<"\n很遗憾，任务没有完成。修改代码，再试一次吧。\n";
	}
	cout<<"\n按[Enter]键返回菜单\n";
	cin.get();
}

int menu()
{
	string input;
	int selection;

	//清屏
	system("cls");

	//显示菜单，接受输入
	cout << "                 Wawa Game 菜单\n"
		<< "任务0：演示\n"
		<< "任务1：无障碍的爬山和下山\n"
		<< "任务2：越过固定障碍\n"
		<< "任务3：越过高度不确定、宽度固定、有间距的若干障碍\n"
		<< "任务4：越过高度、宽度和间距都不确定的若干障碍" << endl;
	while (true)
	{
		cout << "输入0-4选择任务，输入5退出 >";
		getline(cin, input);
		if (input.size() == 1)
		{
			selection = input[0] - '0';
			if (0 <= selection && selection <= 5)
				break;
			else
				cout << "输入有误" << endl;
		}
		else
			cout << "输入有误" << endl;
	}

	return selection;
}