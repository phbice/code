/*
	瓦瓦的生活空间
	四面有墙壁，内部分成若干纵横排列的空格，
	每个格子可能是空白的、墙壁、或豆子，
	有一个瓦瓦生活在此空间内。
	
	创 建 人：Zhang Hua
	创建时间：2011-02-20

	修改记录：
	2019-03-01 优化显示效果，消除闪烁。
*/

#ifndef XWAWASPACE_H
#define XWAWASPACE_H

// 空间的宽度和高度的最大值和最小值
const int XWAWAROOM_WIDTH_MAX = 32;
const int XWAWAROOM_HEIGHT_MAX = 12;
const int XWAWAROOM_WIDTH_MIN = 16;
const int XWAWAROOM_HEIGHT_MIN = 8;

// 空间中每一点的值和/或显示状态
const char XWAWAROOM_EMPTY = ' ';		// 空
const char XWAWAROOM_BEAN = '*';		// 有豆子
const char XWAWAROOM_WALL = 'H';		// 墙壁
const char XWAWAROOM_WAWA = 'G';		// 瓦瓦
const char XWAWAROOM_WAWAANDBEAN = '@';	// 有豆子，且瓦瓦也在该点

// 方向
const int XWAWAROOM_DIR_UP = 0;
const int XWAWAROOM_DIR_DOWN = 1;
const int XWAWAROOM_DIR_LEFT = 2;
const int XWAWAROOM_DIR_RIGHT = 3;

// 空间类的定义
class XWawaSpace
{
private:
	int width, height; // 空间的实际宽度和高度
	char data[XWAWAROOM_HEIGHT_MAX][XWAWAROOM_WIDTH_MAX]; // 空间的状态

	int wawa_cx, wawa_cy; // 瓦瓦的位置
	int wawa_ox, wawa_oy; // 瓦瓦移动前的位置

public:
	XWawaSpace(int w=XWAWAROOM_WIDTH_MIN, int h=XWAWAROOM_HEIGHT_MIN);

	// 初始化
	void init();

	// 用指定的状态进行初始化
	void init(char data[XWAWAROOM_HEIGHT_MAX][XWAWAROOM_WIDTH_MAX]);

	// 清空画布
	void clearAll();

	// 绘制空间中的一个点
	void paintPoint(int x, int y);

	// 绘制空间
	void paint();

	// 重新绘制空间
	void repaint();

	// 获得空间的尺寸
	void getRect(int &width, int &height);

	// 设置点的状态
	void setPoint(int x, int y, char value);

	// 获得点的状态
	char getPoint(int x, int y);

	// 设置瓦瓦的位置
	void setWawaPos(int x, int y);

	// 获得瓦瓦的位置
	void getWawaPos(int &x, int &y);

	// 按指定方向移动瓦瓦
	bool moveWawa(int dir);

	// 指定方向的相邻位置是否无墙
	bool isClear(int dir);

	// 空间是否无豆子
	bool isEmpty();

	// 根据捡豆子任务（瓦瓦从左下角移动到右侧，并把所有的豆子捡起来）构建空间
	// 任务0：演示
	// 任务1：无障碍的爬山和下山
	// 任务2：越过固定障碍
	// 任务3：越过高度不确定、宽度固定、有间距的若干障碍
	// 任务4：越过高度、宽度和间距都不确定的若干障碍
	void build(int task);

	// 检查任务是否已完成
	bool check();
};

#endif