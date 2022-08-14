//
// 基于FLTK 1.1.10的图形库基础版
// 图形类的实现
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
// Modified by ZhangHua @ 2018-10-28
// Modified by ZhangHua @ 2019-04-15
//  -增加名称空间xgraphlib
//
// 注意：学生在此文件增加自定义图形类的实现代码。

#include "XShape.h"

#include <FL/Fl.H>
#include <FL/fl_draw.h>

namespace xgraphlib
{

void XShape::AddPoint(XPoint point)
{
	// 把点添加到点集
	points.push_back(point);
}

void XShape::SetPoint(int idx, XPoint point)
{
	// 修改点集中的指定点
	if (idx>=0 && idx<(int)points.size())
	{
		points[idx] = point;
	}
}

void XShape::Move(int dx, int dy)
{
	vector<XPoint>::iterator t;
	for (t = points.begin(); t != points.end(); t++)
	{
		t->xx += dx;
		t->yy += dy;
	}
}

void XShape::Draw()
{
	// 设置画笔的颜色
	fl_color(lineColor.ToInt());

	// 绘出图形
	DrawMe();

	// 恢复画笔的颜色
	XColor defaultColor;
	fl_color(defaultColor.ToInt());
}

XLine::XLine(XPoint p1, XPoint p2)
{
	// 把直线的两个点添加到点集中
	AddPoint(p1);
	AddPoint(p2);
}

void XLine::DrawMe()
{
	// 使用FLTK中的绘线函数画出直线
	fl_line(points[0].xx, points[0].yy, points[1].xx, points[1].yy);
}

XTriangle::XTriangle(XPoint p1, XPoint p2, XPoint p3)
{
	AddPoint(p1);
	AddPoint(p2);
	AddPoint(p3);
}

void XTriangle::DrawMe()
{
	fl_line(points[0].xx, points[0].yy, points[1].xx, points[1].yy);
	fl_line(points[1].xx, points[1].yy, points[2].xx, points[2].yy);
	fl_line(points[2].xx, points[2].yy, points[0].xx, points[0].yy);
}

XRectangle::XRectangle(XPoint pos, int w, int h)
{
	AddPoint(pos);
	wide = w;
	height = h;
}

void XRectangle::DrawMe()
{
	fl_line(points[0].xx, points[0].yy, points[0].xx + wide, points[0].yy);
	fl_line(points[0].xx, points[0].yy, points[0].xx, points[0].yy + height);
	fl_line(points[0].xx, points[0].yy + height, points[0].xx + wide, points[0].yy + height);
	fl_line(points[0].xx + wide, points[0].yy, points[0].xx + wide, points[0].yy + height);
}

XPolyline::XPolyline(XPoint points[], int points_num)
{
	for (int i = 0; i < points_num; i++)
		this->points.push_back(points[i]);
}

void XPolyline::DrawMe()
{
	vector<XPoint>::iterator t;
	for (t = points.begin(); (t + 1) != points.end(); t++)
		fl_line(t->xx, t->yy, (t + 1)->xx, (t + 1)->yy);
}

XPolygon::XPolygon(XPoint points[], int points_num)
{
	for (int i = 0; i < points_num; i++)
		this->points.push_back(points[i]);
}

void XPolygon::DrawMe()
{
	vector<XPoint>::iterator t;
	for (t = points.begin(); (t + 1) != points.end(); t++)
		fl_line(t->xx, t->yy, (t + 1)->xx, (t + 1)->yy);
	fl_line(t->xx, t->yy, points[0].xx, points[0].yy);
}

void XCircle::DrawMe()
{
	fl_circle(points[0].xx, points[0].yy, radius);
}

XHouse::XHouse(XPoint pos, int w, int h)
	:height(h),
	width(w),
	roof(XTriangle(XPoint(pos.xx - 1.3*w / 2, pos.yy - h), XPoint(pos.xx + 1.3*w / 2, pos.yy - h), XPoint(pos.xx, pos.yy - h - w / 4))),
	wall(XRectangle(XPoint(pos.xx - w / 2, pos.yy - h), w, h))
{
	points.push_back(pos);
}

void XHouse::DrawMe()
{
	wall.DrawMe();
	roof.DrawMe();
}

void XHouse::Move(int dx, int dy)
{
	points[0].xx += dx;
	points[0].yy += dy;
	roof.Move(dx, dy);
	wall.Move(dx, dy);
}
} // namespace xgraphlib

