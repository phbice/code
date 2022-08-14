#ifndef _MYTIME_H_
#define _MYTIME_H_

#include <string>
class MyTime
{
private:
	unsigned long long int seconds;

public:
	MyTime(int s) : seconds(s) {}
	std::string toString();
	bool operator>=(MyTime &t);
};

#endif
