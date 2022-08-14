//  C++������ƣ�201902
//
//	������������
//
//	Created by ZhangHua @ 2015-10
//  Updated by ZhangHua @ 2017-10
//		-����ShowAllPhotos��AddPhoto�����ĳ�ʼ�հ׶��塣
//  Updated by ZhangHua @ 2018-10
//		-�޸�AddPhoto������ֱ����ʾ��λ�ȡϵͳʱ����޸�����ֵ��
//
//  ע�⣺ѧ������ҵҪ���������ĳ�Ա������

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include "XAlbum.h"
#include "XUtility.h"

void XAlbum::Load()
{
	int choice; // �����û�ѡ��Ĺ�������

	// ���Ĳ�������ѭ����ֱ���û�ѡ���˳����Ž���
	do
	{
		// ��ʾ�˵�����ȡҪִ�еĹ�����
		choice = Menu();

		// ���ݹ�������ִ����Ӧ�Ĳ���
		switch (choice)
		{
		case 1: // [1]��ʾȫ����Ƭ�б�
			ShowAllPhotos();
			break;
		case 2: // [2]�����Ƭ
			AddPhoto();
			break;
		case 3: // [3]������Ƭ
			SearchPhoto();
			break;
		case 4: // [4]ɾ����Ƭ
			DeletePhoto();
			break;
		case 5: // [5]�޸���Ƭ
			SetPhoto();
			break;
		case 0:
			std::cout<<"\n�ټ�\n\n"<<endl;
			return;
		}

		// ��ͣ���Ա��û��鿴�������
		system("pause");
	} while (choice != 0);
}

int XAlbum::Menu()
{
	// ��մ����е�����
	system("cls");

	// ��ʾ����������
	std::cout<<"==*==============*==\n";
	std::cout<<"     ���������     \n";
	std::cout<<"      ver  1.2      \n";
	std::cout<<"                    \n";
	std::cout<<"  (C)2015-2019  ZH  \n";
	std::cout<<"--------------------\n";
	std::cout<<"[1]��ʾȫ����Ƭ\n";
	std::cout<<"[2]�����Ƭ\n";
	std::cout<<"[3]������Ƭ\n";
	std::cout<<"[4]ɾ����Ƭ\n";
	std::cout<<"[5]�޸���Ƭ\n";
	std::cout<<"[0]�ر����\n";
	std::cout<<"====================\n";
	
	// �����û�����Ҫִ�еĲ������
	std::cout<<"��ѡ��Ҫִ�еĹ��ܡ�\n";
	std::cout<<"����ù��ܵı�ţ�";
	std::string cstr;
	std::cin>>cstr;
	int choice = atoi(cstr.c_str());
	std::cout<<choice<<std::endl;
	while (choice<0 || choice>5)
	{
		std::cout<<"��������Ч�Ĺ��ܱ�š�\n";
		std::cout<<"���������루1~5��������0�˳�����";
		std::cin>>choice;
	}

	// ������Ч�Ĳ������
	return choice;
}

bool XAlbum::AddPhoto()
{
	// ��������Ƭ����
	XPhoto photo;

	std::cin.get();
	while (true)
	{
		// ����photo��������ʱ��Ϊ��ǰϵͳʱ��
		photo.SetAddDatetime(XUtility::GetCurDateTime());

		// ��ӡ�������Ƭ���Ĵ��룬�������������2���
		// -�����û���������Ƭ����������ֵ
		// -������Ƭ��ӵ�������Ƭ�б�
		std::string photo_title, photo_descr;
		std::cout << "��������Ƭ���⣺";
		std::getline(cin, photo_title);
		if (photo_title.size() == 0)
			break;
		std::cout << "���������Ƭ��������";
		std::getline(cin, photo_descr);
		photo.SetTitle(photo_title);
		photo.SetDescr(photo_descr);

		//����Ƭ��������б�
		m_photo_list.AppendItem(photo);
		// ��ʱ���� true��������޸�
	}
	return true;
}

void show_photo_info(XPhoto &photo)
{
	std::cout<<std::setw(15)<<std::setiosflags(std::ios::left)<<photo.GetTitle()
	         <<std::setw(35)<<std::setiosflags(std::ios::left)<<photo.GetDescr()
	         <<photo.GetAddDatetime()<<std::endl;
}

void XAlbum::ShowAllPhotos()
{
	// ��ӡ���ʾȫ����Ƭ���Ĵ���
	std::cout<<setw(15)<<left<<"����"
		     <<setw(35)<<left<<"����"
			 <<"���ʱ��\n"<<std::string(79,'-')<<std::endl;
	m_photo_list.Traverse(show_photo_info);
}

void XAlbum::SearchPhoto()
{
	std::string keyword;
	std::cin.get();
	std::cout<<"����������ݣ�";
	std::getline(cin, keyword);
	std::cout<<"�����ǰ����ؼ��֡�"<<keyword<<"������Ƭ��Ϣ��\n";
	std::cout<<setw(15)<<left<<"����"
		    <<setw(35)<<left<<"����"
			<<"���ʱ��\n"<<std::string(79,'-')<<std::endl;
	XPhoto photo;
	for (int i = 0; i < m_photo_list.ItemCount(); i++)
	{
		m_photo_list.GetItem(i, photo);
		if (photo.GetTitle().find(keyword, 0) != std::string::npos ||
			photo.GetDescr().find(keyword, 0) != std::string::npos ||
			photo.GetAddDatetime().find(keyword, 0) != std::string::npos)
			show_photo_info(photo);
	}
}

bool XAlbum::DeletePhoto()
{
	int idx;
	cout << "������Ҫɾ������Ƭ����ţ�";
	cin >> idx;
	if (m_photo_list.DeleteItem(idx - 1))
	{
		cout << "��" << idx << "����Ƭ�ѱ�ɾ����" << endl;
		return true;
	}
	else
	{
		cout << "û�е�" << idx << "����Ƭ" << endl;
		return false;
	}
}

bool XAlbum::SetPhoto()
{
	int idx;
	XPhoto photo;
	string photo_title, photo_descr;

	cout << "������Ҫ�޸ĵ���Ƭ����ţ�";
	cin >> idx;
	cin.get();
	m_photo_list.GetItem(idx, photo);

	cout << "�������µ���Ƭ���⣺";
	getline(cin, photo_title);
	std::cout << "���������Ƭ��������";
	std::getline(cin, photo_descr);
	photo.SetTitle(photo_title);
	photo.SetDescr(photo_descr);

	if (m_photo_list.SetItem(idx, photo))
	{
		cout << "��" << idx << "����Ƭ�ѱ��޸ġ�" << endl;
		return true;
	}
	else
	{
		cout << "û�е�" << idx << "����Ƭ" << endl;
		return false;
	}
}
