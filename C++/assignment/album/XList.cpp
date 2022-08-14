//  C++������ƣ�201902
//
//	�б���
//
//	Created by ZhangHua @ 2014-10
//  Updated by ZhangHua @ 2017-10
//		-���岿�ֳ�Ա������
//		-���Ӳ��ֳ�Ա�����ĳ�ʼ�հ׶��塣
//  Updated by ZhangHua @ 2018-10
//		-�޸Ĳ�������˵��
//
//  ע�⣺����Ķ����ѻ�����ɣ�ѧ�����Ը�����ҵҪ��ȫ�����Ա�����Ĵ��롣

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
// ���溯���Ķ��廹δ��ɣ�������Ҫ��Ӵ��롣
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
