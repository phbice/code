//
//	���ù�����
//  �����ṩ��һ��ʵ�õĹ��ܺ�����
//
//	Created by ZhangHua @ 2015-04
//  Updated by ZhangHua @ 2018-04
//		-��string�ദ���ַ���

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "XUtility.h"

string XUtility::GetCurDateTime()
{
	time_t t = time(NULL);
    char tmp[20];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %X", localtime(&t));
	return string(tmp);
}