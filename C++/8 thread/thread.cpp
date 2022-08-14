#include <iostream>
#include <thread>
#include <ctime>
using namespace std;

void proc(int n)
{
    clock_t a = clock();
    while (clock() - a < 2*CLOCKS_PER_SEC) {}
    cout << "I'm a sub thread, n = " << n << endl;
    cout << "My thread ID is " << this_thread::get_id() << endl;
}

int main()
{
    cout << "I'm the main thread" << endl;
    int a = 9;
    thread th2(proc, a);
    cout << "ID of the sub thread is " << th2.get_id() << endl;
    th2.join();
    
    return 0;
}