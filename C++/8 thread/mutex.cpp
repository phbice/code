#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>

using namespace std;

mutex m;

void sleep(double seconds)
{
    clock_t t0 = clock();
    while (clock() - t0 < seconds * CLOCKS_PER_SEC) {}
}
void proc(int n)
{
    for (int i = 0; i < 100; i++)
    {
        m.lock();
        cout << "proc" << n << " " << i << endl;
        m.unlock();
        sleep(0.1);
    }
}

int main()
{
    thread ths[5];
    
    for (int i = 0; i < 5; i++)
    ths[i] = thread(proc, i+1);
    for (thread &t : ths)
        t.join();
    
    return 0;
}
