//
// 基于FLTK 1.1.10的图形类库的测试程序
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2018-10-28
//	-增加展示实现移动动画效果的示例代码
//	-增加更多的注释，并增加更多的空行，让示例代码更醒目
//
// 请同学们在此文件中增加自己的动画脚本代码。

#include "XWindow.h"
using namespace xgraphlib;

int shape_test(int argc, char ** argv);

int main(int argc, char **argv)
{
//	shape_test(argc, argv);
	XInteractiveWindow window(800, 600, (char *)"简易绘图程序");
	XLine ground(XPoint(0, 500), XPoint(800, 500));
	XHouse house(XPoint(400, 500), 100, 70);
	XCircle sun(XPoint(0, 500), 10);

	window.Add(ground);
	window.Add(house);
	window.Add(sun);
	window.show(argc, argv);

	window.WaitForClick();

	int step = 5, delay = 50;
	for (int i = 0; i < 800 / step; i++)
	{
		sun.Move(step, i * step / 200 - 2);
		window.Delay(delay);
	}

	window.WaitForClick();

	window.Clear();
	window.WaitForClick();
	return 0;
}

int shape_test(int argc, char ** argv)
{
	// ==================================================
	// 创建并显示交互式的绘图窗口
	XInteractiveWindow window(600, 400, (char *)"简易动画程序（基础版）");
	window.show(argc, argv);
	// ==================================================


	// 暂停，等待单击“下一步”按钮后继续执行后面的语句
	window.WaitForClick();


	// ==================================================
	// 下面的代码展示如何创建形状对象，并添加到窗口中自动绘制
	// 创建一条直线
	XLine line1(XPoint(100, 100), XPoint(100, 200));
	// 把该直线添加到窗口中
	window.Add(line1);
	// ==================================================


	window.WaitForClick();


	// 创建第二条直线，设置颜色，并添加到窗口中
	XLine line2(XPoint(200, 100), XPoint(300, 100));
	line2.SetLineColor(XColor::XCOLOR_BLUE);
	window.Add(line2);


	window.WaitForClick();

	// 创建三角形
	XTriangle triangle1(XPoint(50, 250), XPoint(70, 350), XPoint(300, 100));
	triangle1.SetLineColor(XColor(60, 200, 170));
	window.Add(triangle1);

	window.WaitForClick();

	// 创建矩形
	XRectangle rectangle1(XPoint(10, 10), 50, 100);
	rectangle1.SetLineColor(XColor(170, 170, 80));
	window.Add(rectangle1);

	window.WaitForClick();

	// 移动矩形
	for (int i = 0; i < 50; i++)
	{
		rectangle1.Move(5, 5);
		window.Delay(20);
	}

	window.WaitForClick();

	// 创建折线
	XPoint polyline_points[5] = { XPoint(100,100), XPoint(110,110), XPoint(120,100), XPoint(130,110), XPoint(140,100) };
	XPolyline polyline1(polyline_points, 5);
	window.Add(polyline1);

	window.WaitForClick();

	// 创建圆
	XCircle circle1(XPoint(200, 150), 70.);
	window.Add(circle1);

	window.WaitForClick();

	// 组合图形：房子
	XHouse house1(XPoint(300, 200), 100, 50);
	window.Add(house1);

	window.WaitForClick();

	// 移动组合图形
	house1.Move(30, 0);

	window.WaitForClick();
	// ==================================================
	// 通过延时函数，实现连续绘图的效果
	// 创建11条直线，并添加到窗口中
	XLine lines[11];
	XPoint startPoint(400, 100);
	for (int i = 0; i < 11; i++)
	{
		lines[i].SetPoint(0, startPoint);
		lines[i].SetPoint(1, XPoint(500, 100 + 10 * i));
		window.Add(lines[i]);

		// 延时50毫秒，然后执行后续操作绘制下一条直线
		window.Delay(50);
	}
	// ==================================================


	window.WaitForClick();


	// ==================================================
	// 展示改变窗口中形状对象的边框颜色，并立即表现出来
	// 改变第二条直线的颜色
	// 注意：line2已经在窗口中，不需要再把它添加到窗口中
	line2.SetLineColor(XColor::XCOLOR_GREEN);
	// ==================================================


	// ==================================================
	// 下面的代码展示移动一个形状对象的动画效果
	// 移动第二条直线
	int step = 5;
	for (int i = 1; i <= 20; i++)
	{
		window.Delay(100);

		// 注意：line2已经在窗口中，不需要再把它添加到窗口中
		//       直接修改它的两个端点的坐标值
		//line2.SetPoint(0, XPoint(200, 100+step*i));
		//line2.SetPoint(1, XPoint(300, 100+step*i));
		line2.Move(0, step);
	}
	// ==================================================


	window.WaitForClick();


	// ==================================================
	// 擦除窗口中的所有图形
	window.Clear();
	// 提示：如果想擦除某一个图形，需要在窗口类中添加函数
	// ==================================================

	window.WaitForClick();

	return 0;
}