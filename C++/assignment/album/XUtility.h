//
//	���ù�����
//  �����ṩ��һ��ʵ�õĹ��ܺ�����
//
//	Created by ZhangHua @ 2015-04
//  Updated by ZhangHua @ 2018-04
//		-��string�ദ���ַ���
//
//  ע�⣺����Ķ�������ɡ�ѧ��Ҳ���Ը�����Ҫ�Լ�����º�����

#ifndef _XUTILITY_H_
#define _XUTILITY_H_

#include <string>

class XUtility
{
public:
	// ��ȡ��ǰϵͳʱ�䣬ת��Ϊ�ַ�������ʽΪ YYYY-MM-DD hh:mm:ss�������ظ��ַ���
	static std::string GetCurDateTime();
};

#endif