//  C++程序设计，201902
//
//	个人相册程序的相册类
//	相册类提供相册的人机界面，管理相册中照片的操作函数。
//
//	Created by ZhangHua @ 2015-10
//  Updated by ZhangHua @ 2017-10
//		-增加ShowAllPhotos和AddPhoto函数的声明
//  Updated by ZhangHua @ 2018-10
//		-调整此类的角色和功能
//
//  注意：学生按作业要求完成相册类的设计和实现。

#ifndef _XALBUM_H_
#define _XALBUM_H_

#include "XList.h"
#include "XPhoto.h"

class XAlbum
{
protected:
	XList m_photo_list; // 相册的照片列表，用列表对象来保存相册中的照片

public:
	// 相册的界面和业务逻辑控制
	void Load();

	// 显示相册程序的功能菜单，并获取用户选择执行的功能项
	// 返回值是用户选择的功能项编号
	int Menu();

	// 显示全部照片
	void ShowAllPhotos();

	// 往相册中添加新照片
	bool AddPhoto();

	// =======================================================
	// 可以在后面添加更多管理照片的成员函数
	// =======================================================

	void SearchPhoto();

	bool DeletePhoto();
	
	bool SetPhoto();
};

#endif