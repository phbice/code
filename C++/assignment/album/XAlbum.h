//  C++������ƣ�201902
//
//	����������������
//	������ṩ�����˻����棬�����������Ƭ�Ĳ���������
//
//	Created by ZhangHua @ 2015-10
//  Updated by ZhangHua @ 2017-10
//		-����ShowAllPhotos��AddPhoto����������
//  Updated by ZhangHua @ 2018-10
//		-��������Ľ�ɫ�͹���
//
//  ע�⣺ѧ������ҵҪ�������������ƺ�ʵ�֡�

#ifndef _XALBUM_H_
#define _XALBUM_H_

#include "XList.h"
#include "XPhoto.h"

class XAlbum
{
protected:
	XList m_photo_list; // ������Ƭ�б����б��������������е���Ƭ

public:
	// ���Ľ����ҵ���߼�����
	void Load();

	// ��ʾ������Ĺ��ܲ˵�������ȡ�û�ѡ��ִ�еĹ�����
	// ����ֵ���û�ѡ��Ĺ�������
	int Menu();

	// ��ʾȫ����Ƭ
	void ShowAllPhotos();

	// ��������������Ƭ
	bool AddPhoto();

	// =======================================================
	// �����ں�����Ӹ��������Ƭ�ĳ�Ա����
	// =======================================================

	void SearchPhoto();

	bool DeletePhoto();
	
	bool SetPhoto();
};

#endif