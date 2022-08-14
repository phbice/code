#ifndef _MYTIME_H_
#define _MYTIME_H_

#include <iostream>
using namespace std;

class MyTime
{
private:
	int seconds;

public:
	MyTime(int s = 0) :seconds(s) {}

	friend ostream & operator<<(ostream & os, MyTime & time);
	friend istream & operator>>(istream & is, MyTime & time);
	MyTime operator++();
	MyTime operator++(int);
	MyTime operator+(MyTime time);
};

#endif
