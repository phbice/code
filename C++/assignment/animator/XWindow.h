//
// 基于FLTK 1.1.10的图形类库基础版
// 窗口类
// XWindow(绘图窗口)
//   XInteractiveWindow（带一个按钮的交互窗口）
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2018-10-28
// Modified by ZhangHua @ 2019-04-15
//  -增加名称空间xgraphlib
//
// 如果不增加新功能，就不必修改此文件中的代码。

#ifndef _XWINDOW_H_
#define _XWINDOW_H_

#include <vector>
using namespace std;

#include <windows.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "XShape.h"

namespace xgraphlib
{

// 绘图窗口
//   可以添加图形对象，并绘制这些图形对象
class XWindow : public Fl_Window
{
private:
	vector<XShape*> shapes; // 形状集，保存要在窗口中绘制的形状对象

public:
	XWindow(int w, int h, char* c=0) : Fl_Window(w, h, c) {}

protected:
	// 重写父类中的对应函数，完成图形的绘制
	void draw();

public:
	// 添加形状，注意参数类型是引用
	void Add(XShape& shape);
	// 清空窗口
	void Clear();
};

} // namespace xgraphlib


#include <FL/Fl_Button.H>

namespace xgraphlib
{

// 交互式绘图窗口
//   包括一个按钮，为窗口提供简单的交互功能
class XInteractiveWindow : public XWindow
{
private:
	Fl_Button button; // “下一步”按钮
	bool buttonClicked; // “下一步”按钮是否被单击

public:
	XInteractiveWindow(int w, int h, char c[]) : XWindow(w, h, c),
		button(w-70, 0, 70, 20, "下一步"), buttonClicked(false)
	{
		// 设置响应单击“下一步”按钮事件的回调函数
		button.callback(CbNext);
	}

	// 在单击“下一步”按钮之前保持窗口（暂停），并强制重画窗口
	void WaitForClick();

	// 延时ms毫秒
	void Delay(unsigned ms);

	// 对单击“下一步”按钮事件的处理
	void Next()
	{
		buttonClicked = true;
	}

	// “下一步”按钮事件的回调函数
	static void CbNext(Fl_Widget* pWidget, void*);
};

} // namespace xgraphlib

#endif