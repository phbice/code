//
//	公用工具类
//  此类提供了一组实用的功能函数。
//
//	Created by ZhangHua @ 2015-04
//  Updated by ZhangHua @ 2018-04
//		-用string类处理字符串

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