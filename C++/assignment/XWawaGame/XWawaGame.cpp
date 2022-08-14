/*
	��C++������ơ��γ�ʵ����ҵ���ṹ��������ƺͻ��ڶ�������ϰ
	�������߼���Ϸ
	����Ϊ���߷��䲻ͬ������Ȼ��������߼񶹵�����·���㷨������д������룬ִ�г�����֤���

	�� �� �ˣ�Zhang Hua
	����ʱ�䣺2011-02-20

	�޸ļ�¼��
	2019-03-01 �޸�������C�����롣
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
using namespace std;

#include "XWawa.h"

#define VS2017 // ������õĲ���VS2010���Ͱ�VS2010�ĳ������õ�IDE�����ƣ�����VS2017��DEVCPP

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
		// menu������չʾ�˵������û���������ȡ����
		task_num = menu();
		if (task_num == 5)
			break;
		wawa.assignTask(task_num);

		// ��ʾ�����������ʼִ�к����ָ����������㷨ʵ�֣�
		BEGIN();

		// ----------------------ָ�ʼ----------------------------

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

		// ----------------------ָ�����----------------------------

		// ��������ָ��ִ�к��Ƿ���������񣬲�������Ӧ����ʾ
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
	cout<<"\n��[Enter]����ʼִ��ָ��";
	char c = cin.get();
}

void END(XWawa &wawa)
{
	cout<<"\nָ����ִ�У����ڼ������������......\n";
	if (wawa.taskIsAccomplished())
	{
		cout<<"\n��ϲ����������ɡ������ƶ���"<<wawa.GetMoveCount()<<"�Ρ�\n";
	}
	else
	{
		cout<<"\n���ź�������û����ɡ��޸Ĵ��룬����һ�ΰɡ�\n";
	}
	cout<<"\n��[Enter]�����ز˵�\n";
	cin.get();
}

int menu()
{
	string input;
	int selection;

	//����
	system("cls");

	//��ʾ�˵�����������
	cout << "                 Wawa Game �˵�\n"
		<< "����0����ʾ\n"
		<< "����1�����ϰ�����ɽ����ɽ\n"
		<< "����2��Խ���̶��ϰ�\n"
		<< "����3��Խ���߶Ȳ�ȷ������ȹ̶����м��������ϰ�\n"
		<< "����4��Խ���߶ȡ���Ⱥͼ�඼��ȷ���������ϰ�" << endl;
	while (true)
	{
		cout << "����0-4ѡ����������5�˳� >";
		getline(cin, input);
		if (input.size() == 1)
		{
			selection = input[0] - '0';
			if (0 <= selection && selection <= 5)
				break;
			else
				cout << "��������" << endl;
		}
		else
			cout << "��������" << endl;
	}

	return selection;
}