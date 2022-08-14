//
// 基于FLTK 1.1.10的图形库基础版
// 图形类
// XPoint（点）
// XShape（形状）
//   XLine（直线）
// XColor（颜色）
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
// Modified by ZhangHua @ 2018-10-28
// Modified by ZhangHua @ 2019-04-15
//  -增加名称空间xgraphlib
//
// 学生在此文件中定义自己的图形类。

#ifndef _XSHAPE_H_
#define _XSHAPE_H_

#include <vector>
using namespace std;

#include "FL/fl_draw.h"

namespace xgraphlib
{

// 点
class XPoint
{
public:
	int xx, yy; // 点的坐标值

	XPoint(int x=0, int y=0) { xx=x; yy=y; }
};

// 颜色（重新包装FLTK中的颜色）
class XColor
{
private:
	Fl_Color cc; // 颜色值

public:
	enum XColorType
	{
		XCOLOR_RED = FL_RED,
		XCOLOR_GREEN = FL_GREEN,
		XCOLOR_BLUE = FL_BLUE,
		XCOLOR_YELLOW = FL_YELLOW,
		XCOLOR_WHITE = FL_WHITE,
		XCOLOR_BLACK = FL_BLACK
	};

	XColor(XColorType c=XCOLOR_RED) : cc(Fl_Color(c)) { }
	XColor(unsigned char r, unsigned char g, unsigned char b)
	{
		cc = fl_rgb_color(r, g, b);
	}

	int ToInt() { return cc; }
};

// 形状类
// 注意：学生可以在此类中增加新成员
class XShape
{
private:
	XColor lineColor; // 线段颜色

protected:
	vector<XPoint> points; // 点集

public:
	XShape() : lineColor() {}

	// 添加点
	void AddPoint(XPoint point);
	// 修改某一点的值
	void SetPoint(int idx, XPoint point);
	// 设置线段颜色
	void SetLineColor(XColor c) { lineColor = c; }
	// 平移
	void Move(int dx, int dy);
	// 绘制图形（包括设置画笔颜色、绘出线段、恢复画笔的颜色）
	void Draw();

protected:
	// 绘制某一种具体图形（只有具体的类才能实现）
	// 注意：这是一个纯虚函数，在每一个非抽象子类中必须重新声明和定义此函数！
	virtual void DrawMe() = 0;
};

// 直线
class XLine : public XShape
{
public:
	// 直线包括两个点
	XLine(XPoint p1=XPoint(0, 0), XPoint p2=XPoint(0, 0));

	// 绘出直线
	void DrawMe();
};

// 三角形
class XTriangle : public XShape
{
public:
	XTriangle(XPoint p1, XPoint p2, XPoint p3);

	void DrawMe();
};

// 矩形
class XRectangle : public XShape
{
private:
	int wide;
	int height;

public:
	XRectangle(XPoint pos, int w, int h);

	void DrawMe();
};

// 折线
class XPolyline : public XShape
{
public:
	XPolyline(XPoint points[], int points_num);

	void DrawMe();
};

// 多边形
class XPolygon : public XShape
{
public:
	XPolygon(XPoint points[], int points_num);

	void DrawMe();
};

// 圆
class XCircle : public XShape
{
private:
	double radius; // 半径
public:
	XCircle(XPoint centre, double r) : radius(r) { points.push_back(centre); }

	void DrawMe();
};

// 组合图形
class XHouse : public XShape
{
private:
	int height;
	int width;
	XTriangle roof;
	XRectangle wall;

public:
	XHouse(XPoint pos, int w, int h);

	void Move(int dx, int dy);
	void DrawMe();
};
} // namespace xgraphlib

#endif