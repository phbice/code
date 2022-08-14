#include "MyTime.h"

ostream & operator<<(ostream & os, MyTime & time)
{
	os << time.seconds / 3600 << "H"
		<< (time.seconds % 3600) / 60 << "M"
		<< time.seconds % 3600 % 60 << "S";
	return os;
}

istream & operator>>(istream & is, MyTime & time)
{
	is >> time.seconds;
	return is;
}

MyTime MyTime::operator++()
{
	seconds++;
	return *this;
}

MyTime MyTime::operator++(int)
{
	MyTime temp(*this);
	seconds++;
	return temp;
}

MyTime MyTime::operator+(MyTime time)
{
	return MyTime(seconds + time.seconds);
}