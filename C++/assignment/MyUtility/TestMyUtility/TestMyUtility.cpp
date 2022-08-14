#include <iostream>
using namespace std;

#include "MyUtility/MyTime.h"

int main()
{
	MyTime time1(1000);
	MyTime time2(20000);
	MyTime time3;
	cout << "time1 = " << time1 << "  time2 = " << time2 << endl;
	time1++;
	cout << "time1++\ntime1 = " << time1 << endl;
	cout << "Input time1(s): ";
	cin >> time1;
	cout << "time1 = " << time1 << endl;
	time3 = time1 + time2;
	cout << "time3 = time1 + time2 = " << time3 << endl;
	time3 = time3 + 125;
	cout << "time3 + 125S = " << time3 << endl;
	return 0;
}
