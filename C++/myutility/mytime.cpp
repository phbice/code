#include "mytime.h"
#include <sstream>

std::string MyTime::toString()
{
	std::stringstream ss;
	ss << seconds / 3600 << "H"
		<< seconds % 3600 << "M"
		<< seconds % 60 << "S";
	return ss.str();
}

bool MyTime::operator>=(MyTime &t)
{
	return seconds >= t.seconds;
}