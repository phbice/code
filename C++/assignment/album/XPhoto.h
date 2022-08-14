//  C++程序设计，201902
//
//	相册程序的照片类
//	照片类定义照片的数据成员（属性）和操作数据成员的函数（方法）
//
//	Created by ZhangHua @ 2015-10
//  Updated by ZhangHua @ 2018-04
//		-用string类处理字符串
//  Updated by ZhangHua @ 2018-10
//		-修改部分文字说明
//
//  注意：学生按作业要求完成照片类的设计和实现。

#ifndef _XPHOTO_H_
#define _XPHOTO_H_

#include <string>
using std::string;

// 照片
class XPhoto
{
private:
	unsigned int m_id; // 可选属性：照片编号（用来唯一标识一张照片）。最好是自己设计一个自动编号的算法。

	string m_title; // 标题
	string m_descr; // 说明
	string m_add_datetime; // 入册时间

	// =======================================================
	// 可以在后面添加其他属性(数据成员)
	// =======================================================



public:
	// =======================================================
	// 私有属性的Setter和Getter函数（修改和读取函数）
	// 如果在XPhoto类中增加了新的属性,则需要增加相应的Setter和Getter函数
	// -------------------------------------------------------
	void SetTitle(const string &title) { m_title = title; }
	string GetTitle() { return m_title; }
	void SetDescr(const string &descr) { m_descr = descr; }
	string GetDescr() { return m_descr; }
	void SetAddDatetime(const string &add_datetime) { m_add_datetime = add_datetime; }
	string GetAddDatetime() { return m_add_datetime; }


	// =======================================================
	// 可以在后面添加操作函数
	// =======================================================



};

#endif