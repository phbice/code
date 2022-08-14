//
// ����FLTK 1.1.10��ͼ�ο������
// ͼ����
// XPoint���㣩
// XShape����״��
//   XLine��ֱ�ߣ�
// XColor����ɫ��
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
// Modified by ZhangHua @ 2018-10-28
// Modified by ZhangHua @ 2019-04-15
//  -�������ƿռ�xgraphlib
//
// ѧ���ڴ��ļ��ж����Լ���ͼ���ࡣ

#ifndef _XSHAPE_H_
#define _XSHAPE_H_

#include <vector>
using namespace std;

#include "FL/fl_draw.h"

namespace xgraphlib
{

// ��
class XPoint
{
public:
	int xx, yy; // �������ֵ

	XPoint(int x=0, int y=0) { xx=x; yy=y; }
};

// ��ɫ�����°�װFLTK�е���ɫ��
class XColor
{
private:
	Fl_Color cc; // ��ɫֵ

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

// ��״��
// ע�⣺ѧ�������ڴ����������³�Ա
class XShape
{
private:
	XColor lineColor; // �߶���ɫ

protected:
	vector<XPoint> points; // �㼯

public:
	XShape() : lineColor() {}

	// ��ӵ�
	void AddPoint(XPoint point);
	// �޸�ĳһ���ֵ
	void SetPoint(int idx, XPoint point);
	// �����߶���ɫ
	void SetLineColor(XColor c) { lineColor = c; }
	// ƽ��
	void Move(int dx, int dy);
	// ����ͼ�Σ��������û�����ɫ������߶Ρ��ָ����ʵ���ɫ��
	void Draw();

protected:
	// ����ĳһ�־���ͼ�Σ�ֻ�о���������ʵ�֣�
	// ע�⣺����һ�����麯������ÿһ���ǳ��������б������������Ͷ���˺�����
	virtual void DrawMe() = 0;
};

// ֱ��
class XLine : public XShape
{
public:
	// ֱ�߰���������
	XLine(XPoint p1=XPoint(0, 0), XPoint p2=XPoint(0, 0));

	// ���ֱ��
	void DrawMe();
};

// ������
class XTriangle : public XShape
{
public:
	XTriangle(XPoint p1, XPoint p2, XPoint p3);

	void DrawMe();
};

// ����
class XRectangle : public XShape
{
private:
	int wide;
	int height;

public:
	XRectangle(XPoint pos, int w, int h);

	void DrawMe();
};

// ����
class XPolyline : public XShape
{
public:
	XPolyline(XPoint points[], int points_num);

	void DrawMe();
};

// �����
class XPolygon : public XShape
{
public:
	XPolygon(XPoint points[], int points_num);

	void DrawMe();
};

// Բ
class XCircle : public XShape
{
private:
	double radius; // �뾶
public:
	XCircle(XPoint centre, double r) : radius(r) { points.push_back(centre); }

	void DrawMe();
};

// ���ͼ��
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