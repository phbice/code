//
// 基于FLTK 1.1.10的图形类库基础版
// 窗口类的实现
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2018-10-28
// Modified by ZhangHua @ 2019-04-15
//  -增加名称空间xgraphlib
//
// 如果不增加新功能，就不必修改此文件中的代码。

#include "XWindow.h"

namespace xgraphlib
{

void XWindow::Add(XShape& shape)
{
	shapes.push_back(&shape);
}

void XWindow::Clear()
{
	shapes.clear();
}

void XWindow::draw()
{
	Fl_Window::draw();

	// 调用形状集中每一个形状对象的Draw函数，绘制图形
	for (int i=0; i<(int)shapes.size(); i++)
	{
		shapes[i]->Draw();
	}
}

void XInteractiveWindow::WaitForClick()
{
	while (!buttonClicked) Fl::wait();
	buttonClicked = false;
	Fl::redraw();
}

void XInteractiveWindow::Delay(unsigned ms)
{
	Fl::wait();
	Sleep(ms);
	Fl::redraw();
}

void XInteractiveWindow::CbNext(Fl_Widget* pWidget, void*)
{
	if (pWidget)
	{
		void* pWnd = pWidget->window();
		if (pWnd)
		{
			((XInteractiveWindow*)pWnd)->Next();
		}
	}
}

} // namespace xgraphlib