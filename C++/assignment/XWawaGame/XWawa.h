/*
	瓦瓦捡豆子游戏程序
	用于《C++语言程序设计》课程，通过比较形象的、易接受的方式让学生去练习结构化程序设计和基于对象编程。

	瓦瓦
	一种人工智能体，生活在独立的空间中。
	在瓦瓦的空间中，它可以上下左右移动，每次移动一格，不能直接穿越墙壁，
	可以在某一格捡起或放下一粒豆子。

	瓦瓦的生活空间
	四面有墙壁，内部分成若干纵横排列的空格，
	每个格子可能是空白的、墙壁、或豆子，
	有一个瓦瓦生活在此空间内。
	
	创 建 人：Zhang Hua
	创建时间：2011-02-20

	修改记录：
	2017-09-19 把XWawaSpace类的代码移出，保存在单独的文件中。
	2014-03-04 去掉效果不好的速度调节功能。
	           增加瓦瓦移动次数统计功能。
	2012-10-05 把设置任务操作移到XWawaSpace中，要求学生设计和定义自己的XWawa。
*/

#ifndef XWAWA_H
#define XWAWA_H

#include "XWawaSpace.h"

// 瓦瓦类的定义
class XWawa
{
private:
	int moveCount; // 移动次数

protected:
	XWawaSpace space; // 空间

public:
	XWawa();

	// 移动
	void moveUp();				// 向上
	void moveDown();			// 向下
	void moveLeft();			// 向左
	void moveRight();			// 向右

	int GetMoveCount() { return moveCount; }

	// 再当前位置捡豆子和放豆子
	void pickupBean();				// 捡豆子
	void putdownBean();				// 放豆子

	// 判断周围（当前位置的相邻格子）有无墙壁（障碍物）
	bool leftIsClear();			// 左边
	bool rightIsClear();		// 右边
	bool upsideIsClear();		// 上边
	bool downsideIsClear();		// 下方

	// 判断当前位置有无豆子
	bool beanIsHere();

	// 分配捡豆子任务（也可以参考XWawaSpace.h中XWawaSpace::build函数的说明）
	// 任务0：演示
	// 任务1：无障碍的爬山和下山
	// 任务2：越过固定障碍
	// 任务3：越过高度不确定、宽度固定、有间距的若干障碍
	// 任务4：越过高度、宽度和间距都不确定的若干障碍
	void assignTask(int task);

	// 检查任务是否已完成（捡完全部豆子）
	bool taskIsAccomplished();
};

#endif