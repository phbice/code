//  C++程序设计，201902
//
//	相册应用程序
//
//	Created by ZhangHua @ 2015-10
//  Updated by ZhangHua @ 2017-10
//		-增加相册对象；修改初始提示。
//  Updated by ZhangHua @ 2018-04
//		-修改部分提示信息。
//  Updated by ZhangHua @ 2018-10
//		-调整应用程序的功能设置，把相册的业务功能放入相册类。
//
//  注意：此类的定义已完成。学生也可以根据自己的需要修改。

#include "XAlbum.h"

// 相册程序的主控函数
int main(void)
{
	XAlbum myAlbum; // 相册对象

	// 加载相册，并执行照片管理业务
	myAlbum.Load();

	return 0;
}
