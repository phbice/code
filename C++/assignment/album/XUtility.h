//
//	公用工具类
//  此类提供了一组实用的功能函数。
//
//	Created by ZhangHua @ 2015-04
//  Updated by ZhangHua @ 2018-04
//		-用string类处理字符串
//
//  注意：此类的定义已完成。学生也可以根据需要自己添加新函数。

#ifndef _XUTILITY_H_
#define _XUTILITY_H_

#include <string>

class XUtility
{
public:
	// 获取当前系统时间，转换为字符串（格式为 YYYY-MM-DD hh:mm:ss），返回该字符串
	static std::string GetCurDateTime();
};

#endif