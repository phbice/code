//  C++程序设计，201902
//
//	列表类
//
//	Created by ZhangHua @ 2014-10
//  Updated by ZhangHua @ 2017-10
//		-定义部分成员函数；
//		-增加部分成员函数的初始空白定义。
//  Updated by ZhangHua @ 2018-10
//		-修改部分文字说明
//
//  注意：此类的定义已基本完成，学生可以根据作业要求补全所需成员函数的代码。

#include "XList.h"

XList::XList()
{
	Initialize();
}

void XList::Initialize()
{
	m_items = 0;
}

bool XList::IsEmpty()
{
	if (m_items==0)
		return true;
	else
		return false;
}

bool XList::IsFull()
{
	if (m_items>=LISTSIZE)
		return true;
	else
		return false;
}

int XList::ItemCount()
{
	return m_items;
}

bool XList::AppendItem(Item &item)
{
	if (IsFull()) return false;

	m_entries[m_items] = item;
	m_items++;

	return true;
}

void XList::Traverse(void (*pFun)(Item &item))
{
	for (int i=0; i<m_items; i++)
	{
		pFun(m_entries[i]);
	}
}

void XList::Clear()
{
	m_items = 0;
}


// =======================================================
// 后面函数的定义还未完成，你视需要添加代码。
// =======================================================

bool XList::SetItem(int idx, Item &item)
{
	if (0 <= idx && idx < m_items)
	{
		m_entries[idx] = item;
		return true;
	}
	else
		return false;
}

bool XList::GetItem(int idx, Item &item)
{
	if (0 <= idx && idx < m_items)
	{
		item = m_entries[idx];
		return true;
	}
	else
		return false;
}

bool XList::DeleteItem(int idx)
{
	if (0 <= idx && idx < m_items)
	{
		for (int i = idx; i < m_items-1; i++)
			m_entries[i] = m_entries[i + 1];
		m_items--;
		return true;
	}
	else
		return false;
}
