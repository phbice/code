#ifndef _CLASS_H_
#define _CLASS_H_

#include <vector>
#include <string>
using std::vector;
using std::string;
class ClassTime // һ�οε�ʱ��
{
private:
	int week_begin, week_end;   // ����һ�ܵ���һ�ܼ����Ͽ�
	int week_flag; // ����˫�ܻ���ȫ��
	vector<vector<int>> time; // ÿһ�ܵ���һ����Ǽ��ڿ�
public:
	ClassTime(int i_week_begin, int i_week_end, int i_week_flag = 0);
	bool AddClass(int day, int time);
	string ToString();
};

class Class
{
private:
	int semester; // ѧ��
	string name;
	int type; // �γ���𣬹���/רҵ��ѡ��/����
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