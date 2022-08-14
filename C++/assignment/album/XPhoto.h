//  C++������ƣ�201902
//
//	���������Ƭ��
//	��Ƭ�ඨ����Ƭ�����ݳ�Ա�����ԣ��Ͳ������ݳ�Ա�ĺ�����������
//
//	Created by ZhangHua @ 2015-10
//  Updated by ZhangHua @ 2018-04
//		-��string�ദ���ַ���
//  Updated by ZhangHua @ 2018-10
//		-�޸Ĳ�������˵��
//
//  ע�⣺ѧ������ҵҪ�������Ƭ�����ƺ�ʵ�֡�

#ifndef _XPHOTO_H_
#define _XPHOTO_H_

#include <string>
using std::string;

// ��Ƭ
class XPhoto
{
private:
	unsigned int m_id; // ��ѡ���ԣ���Ƭ��ţ�����Ψһ��ʶһ����Ƭ����������Լ����һ���Զ���ŵ��㷨��

	string m_title; // ����
	string m_descr; // ˵��
	string m_add_datetime; // ���ʱ��

	// =======================================================
	// �����ں��������������(���ݳ�Ա)
	// =======================================================



public:
	// =======================================================
	// ˽�����Ե�Setter��Getter�������޸ĺͶ�ȡ������
	// �����XPhoto�����������µ�����,����Ҫ������Ӧ��Setter��Getter����
	// -------------------------------------------------------
	void SetTitle(const string &title) { m_title = title; }
	string GetTitle() { return m_title; }
	void SetDescr(const string &descr) { m_descr = descr; }
	string GetDescr() { return m_descr; }
	void SetAddDatetime(const string &add_datetime) { m_add_datetime = add_datetime; }
	string GetAddDatetime() { return m_add_datetime; }


	// =======================================================
	// �����ں�����Ӳ�������
	// =======================================================



};

#endif