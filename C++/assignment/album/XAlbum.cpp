//  C++程序设计，201902
//
//	相册程序的相册类
//
//	Created by ZhangHua @ 2015-10
//  Updated by ZhangHua @ 2017-10
//		-增加ShowAllPhotos和AddPhoto函数的初始空白定义。
//  Updated by ZhangHua @ 2018-10
//		-修改AddPhoto函数，直接演示如何获取系统时间和修改属性值。
//
//  注意：学生按作业要求定义相册类的成员函数。

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include "XAlbum.h"
#include "XUtility.h"

void XAlbum::Load()
{
	int choice; // 保存用户选择的功能项编号

	// 相册的操作控制循环，直到用户选择“退出”才结束
	do
	{
		// 显示菜单，获取要执行的功能项
		choice = Menu();

		// 根据功能项编号执行相应的操作
		switch (choice)
		{
		case 1: // [1]显示全部照片列表
			ShowAllPhotos();
			break;
		case 2: // [2]添加照片
			AddPhoto();
			break;
		case 3: // [3]查找照片
			SearchPhoto();
			break;
		case 4: // [4]删除照片
			DeletePhoto();
			break;
		case 5: // [5]修改照片
			SetPhoto();
			break;
		case 0:
			std::cout<<"\n再见\n\n"<<endl;
			return;
		}

		// 暂停，以便用户查看操作结果
		system("pause");
	} while (choice != 0);
}

int XAlbum::Menu()
{
	// 清空窗口中的内容
	system("cls");

	// 显示相册操作界面
	std::cout<<"==*==============*==\n";
	std::cout<<"     满天星相册     \n";
	std::cout<<"      ver  1.2      \n";
	std::cout<<"                    \n";
	std::cout<<"  (C)2015-2019  ZH  \n";
	std::cout<<"--------------------\n";
	std::cout<<"[1]显示全部照片\n";
	std::cout<<"[2]添加照片\n";
	std::cout<<"[3]查找照片\n";
	std::cout<<"[4]删除照片\n";
	std::cout<<"[5]修改照片\n";
	std::cout<<"[0]关闭相册\n";
	std::cout<<"====================\n";
	
	// 引导用户输入要执行的操作编号
	std::cout<<"请选择要执行的功能。\n";
	std::cout<<"输入该功能的编号：";
	std::string cstr;
	std::cin>>cstr;
	int choice = atoi(cstr.c_str());
	std::cout<<choice<<std::endl;
	while (choice<0 || choice>5)
	{
		std::cout<<"输入了无效的功能编号。\n";
		std::cout<<"请重新输入（1~5），输入0退出程序：";
		std::cin>>choice;
	}

	// 返回有效的操作编号
	return choice;
}

bool XAlbum::AddPhoto()
{
	// 定义新照片对象
	XPhoto photo;

	std::cin.get();
	while (true)
	{
		// 设置photo对象的入册时间为当前系统时间
		photo.SetAddDatetime(XUtility::GetCurDateTime());

		// 添加“增加照片”的代码，即至少完成以下2项功能
		// -引导用户输入新照片的其他属性值
		// -把新照片添加到相册的照片列表
		std::string photo_title, photo_descr;
		std::cout << "请输入照片标题：";
		std::getline(cin, photo_title);
		if (photo_title.size() == 0)
			break;
		std::cout << "请输入对照片的描述：";
		std::getline(cin, photo_descr);
		photo.SetTitle(photo_title);
		photo.SetDescr(photo_descr);

		//将照片对象加入列表
		m_photo_list.AppendItem(photo);
		// 暂时返回 true，你可以修改
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
	// 添加“显示全部照片”的代码
	std::cout<<setw(15)<<left<<"标题"
		     <<setw(35)<<left<<"描述"
			 <<"入册时间\n"<<std::string(79,'-')<<std::endl;
	m_photo_list.Traverse(show_photo_info);
}

void XAlbum::SearchPhoto()
{
	std::string keyword;
	std::cin.get();
	std::cout<<"输入查找内容：";
	std::getline(cin, keyword);
	std::cout<<"以下是包含关键字“"<<keyword<<"”的照片信息：\n";
	std::cout<<setw(15)<<left<<"标题"
		    <<setw(35)<<left<<"描述"
			<<"入册时间\n"<<std::string(79,'-')<<std::endl;
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
	cout << "请输入要删除的照片的序号：";
	cin >> idx;
	if (m_photo_list.DeleteItem(idx - 1))
	{
		cout << "第" << idx << "张照片已被删除。" << endl;
		return true;
	}
	else
	{
		cout << "没有第" << idx << "张照片" << endl;
		return false;
	}
}

bool XAlbum::SetPhoto()
{
	int idx;
	XPhoto photo;
	string photo_title, photo_descr;

	cout << "请输入要修改的照片的序号：";
	cin >> idx;
	cin.get();
	m_photo_list.GetItem(idx, photo);

	cout << "请输入新的照片标题：";
	getline(cin, photo_title);
	std::cout << "请输入对照片的描述：";
	std::getline(cin, photo_descr);
	photo.SetTitle(photo_title);
	photo.SetDescr(photo_descr);

	if (m_photo_list.SetItem(idx, photo))
	{
		cout << "第" << idx << "张照片已被修改。" << endl;
		return true;
	}
	else
	{
		cout << "没有第" << idx << "张照片" << endl;
		return false;
	}
}
