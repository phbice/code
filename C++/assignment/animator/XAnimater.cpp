//
// ����FLTK 1.1.10��ͼ�����Ĳ��Գ���
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2018-10-28
//	-����չʾʵ���ƶ�����Ч����ʾ������
//	-���Ӹ����ע�ͣ������Ӹ���Ŀ��У���ʾ���������Ŀ
//
// ��ͬѧ���ڴ��ļ��������Լ��Ķ����ű����롣

#include "XWindow.h"
using namespace xgraphlib;

int shape_test(int argc, char ** argv);

int main(int argc, char **argv)
{
//	shape_test(argc, argv);
	XInteractiveWindow window(800, 600, (char *)"���׻�ͼ����");
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
	// ��������ʾ����ʽ�Ļ�ͼ����
	XInteractiveWindow window(600, 400, (char *)"���׶������򣨻����棩");
	window.show(argc, argv);
	// ==================================================


	// ��ͣ���ȴ���������һ������ť�����ִ�к�������
	window.WaitForClick();


	// ==================================================
	// ����Ĵ���չʾ��δ�����״���󣬲���ӵ��������Զ�����
	// ����һ��ֱ��
	XLine line1(XPoint(100, 100), XPoint(100, 200));
	// �Ѹ�ֱ����ӵ�������
	window.Add(line1);
	// ==================================================


	window.WaitForClick();


	// �����ڶ���ֱ�ߣ�������ɫ������ӵ�������
	XLine line2(XPoint(200, 100), XPoint(300, 100));
	line2.SetLineColor(XColor::XCOLOR_BLUE);
	window.Add(line2);


	window.WaitForClick();

	// ����������
	XTriangle triangle1(XPoint(50, 250), XPoint(70, 350), XPoint(300, 100));
	triangle1.SetLineColor(XColor(60, 200, 170));
	window.Add(triangle1);

	window.WaitForClick();

	// ��������
	XRectangle rectangle1(XPoint(10, 10), 50, 100);
	rectangle1.SetLineColor(XColor(170, 170, 80));
	window.Add(rectangle1);

	window.WaitForClick();

	// �ƶ�����
	for (int i = 0; i < 50; i++)
	{
		rectangle1.Move(5, 5);
		window.Delay(20);
	}

	window.WaitForClick();

	// ��������
	XPoint polyline_points[5] = { XPoint(100,100), XPoint(110,110), XPoint(120,100), XPoint(130,110), XPoint(140,100) };
	XPolyline polyline1(polyline_points, 5);
	window.Add(polyline1);

	window.WaitForClick();

	// ����Բ
	XCircle circle1(XPoint(200, 150), 70.);
	window.Add(circle1);

	window.WaitForClick();

	// ���ͼ�Σ�����
	XHouse house1(XPoint(300, 200), 100, 50);
	window.Add(house1);

	window.WaitForClick();

	// �ƶ����ͼ��
	house1.Move(30, 0);

	window.WaitForClick();
	// ==================================================
	// ͨ����ʱ������ʵ��������ͼ��Ч��
	// ����11��ֱ�ߣ�����ӵ�������
	XLine lines[11];
	XPoint startPoint(400, 100);
	for (int i = 0; i < 11; i++)
	{
		lines[i].SetPoint(0, startPoint);
		lines[i].SetPoint(1, XPoint(500, 100 + 10 * i));
		window.Add(lines[i]);

		// ��ʱ50���룬Ȼ��ִ�к�������������һ��ֱ��
		window.Delay(50);
	}
	// ==================================================


	window.WaitForClick();


	// ==================================================
	// չʾ�ı䴰������״����ı߿���ɫ�����������ֳ���
	// �ı�ڶ���ֱ�ߵ���ɫ
	// ע�⣺line2�Ѿ��ڴ����У�����Ҫ�ٰ�����ӵ�������
	line2.SetLineColor(XColor::XCOLOR_GREEN);
	// ==================================================


	// ==================================================
	// ����Ĵ���չʾ�ƶ�һ����״����Ķ���Ч��
	// �ƶ��ڶ���ֱ��
	int step = 5;
	for (int i = 1; i <= 20; i++)
	{
		window.Delay(100);

		// ע�⣺line2�Ѿ��ڴ����У�����Ҫ�ٰ�����ӵ�������
		//       ֱ���޸����������˵������ֵ
		//line2.SetPoint(0, XPoint(200, 100+step*i));
		//line2.SetPoint(1, XPoint(300, 100+step*i));
		line2.Move(0, step);
	}
	// ==================================================


	window.WaitForClick();


	// ==================================================
	// ���������е�����ͼ��
	window.Clear();
	// ��ʾ����������ĳһ��ͼ�Σ���Ҫ�ڴ���������Ӻ���
	// ==================================================

	window.WaitForClick();

	return 0;
}