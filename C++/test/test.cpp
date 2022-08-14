#include <iostream>

class Counter
{
private:
	static int count;
public:
	int GetCounter() { count++; return count; }
};

using namespace std;

int Counter::count = 0;

int main()
{
	Counter counterA;
	for (int i = 0; i < 10; i++)
		cout << counterA.GetCounter();
	return 0;
}