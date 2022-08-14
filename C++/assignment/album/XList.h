//  C++程序设计，201902
//
//	列表类
//  列表类属于公用的工具类，用来保存和维护一组项目。
//
//	Created by ZhangHua @ 2014-10
//  Updated by ZhangHua @ 2018-04
//		-不使用常对象参数，避免使用常成员函数；
//		-修改个别函数的名称。
//  Updated by ZhangHua @ 2018-10
//		-修改部分文字说明
//
//  注意：此类的定义已基本完成，学生可以根据作业要求补全所需成员函数的代码。

#ifndef _XLIST_H_
#define _XLIST_H_

#include "XPhoto.h"

typedef XPhoto Item; // 定义列表中的项目类型

class XList
{
public:
	const static int LISTSIZE = 100; // 列表的容量

private:
	Item m_entries[LISTSIZE]; // 用静态数组保存项目
	int m_items; // 当前项目的数量

public:
	// 构造函数
	XList();

	// 初始化
	void Initialize();

	// 判断列表当前是否为空
	bool IsEmpty();

	// 判断列表当前是否已满
	bool IsFull();

	// 获取列表中项目的实际数量
	int ItemCount();

	// 在列表的尾部添加一个项目
	bool AppendItem(Item &item);

	// 把一个函数作用于列表中的每个项目
	void Traverse(void (*pFun)(Item &item));

	// 清空列表
	void Clear();


	// =======================================================
	// 注意：如果你需要以下函数声明的功能，你要自己在cpp文件
	// 中完成这些函数的定义。
	// =======================================================

	// 根据给定的顺序号idx，把item赋值给列表中的项目，并返回true
	// 如果idx有误，则返回false
	bool SetItem(int idx, Item &item);

	// 根据给定的顺序号idx，获取列表中的项目，赋值给item，并返回true
	// 如果idx有误，则返回false
	bool GetItem(int idx, Item &item);

	// 根据给定的顺序号idx，删除列表中的项目，并返回true
	// 如果idx有误，则返回false
	bool DeleteItem(int idx);
};

#endif
