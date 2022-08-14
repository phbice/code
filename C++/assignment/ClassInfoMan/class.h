#ifndef _CLASS_H_
#define _CLASS_H_

#include <vector>
#include <string>
using std::vector;
using std::string;
class ClassTime // 一次课的时间
{
private:
	int week_begin, week_end;   // 从哪一周到哪一周几周上课
	int week_flag; // 单周双周还是全部
	vector<vector<int>> time; // 每一周的那一天的那几节课
public:
	ClassTime(int i_week_begin, int i_week_end, int i_week_flag = 0);
	bool AddClass(int day, int time);
	string ToString();
};

class Class
{
private:
	int semester; // 学期
	string name;
	int type; // 课程类别，公共/专业，选修/必修
	string teacher;
	ClassTime time;
	string location;
	int period;
	int credit;
	int score;
public:
	// Constuctor
	Class(int iSemester, string &iNname, int iType, string &iTeacher, ClassTime &iTime, string &iLocation, int iCreit, int iScore);

	// Setter and Getter

	int semester() { return semester; }
	bool semester(int iSemester);

	string name() { return name; }
	bool name(string iName);

	int type() { return type; }
	bool type(int iType);

	string teacher() { return teacher; }
	bool teacher(string iTeacher);

	ClassTime time() { return time; }
	bool time(ClassTime iTime);

	string location() { return location; }
	bool location();

	int period() { return period; }

	int credit() { return credit; }
	bool credit(int iCredit);

	int score() { return score; }
	bool score(int iScore);

};

ClassTime::ClassTime(int i_week_begin, int i_week_end, int i_week_flag = 0)
{
	week_begin = i_week_begin;
	week_end = i_week_end;
	week_flag = i_week_flag;
}

bool ClassTime::AddClass(int day, int time)
{

}

#endif