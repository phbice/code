#include <iostream>
#include <random>
#include <thread>
#include <mutex>

#include <ctime>
#include <chrono>

using namespace std;

mutex m;

void proc1()
{
    default_random_engine rg((unsigned int)time(NULL));
    uniform_int_distribution<unsigned int> rd(0, 3);
    
    for (int i = 0; i < 20; i++)
    {
        m.lock();
        cout << rd(rg) << "#" << this_thread::get_id() << " ";
        m.unlock();
    }
}


int test1()
{
    default_random_engine re;
    uniform_int_distribution<unsigned int> rng(0, 3);
    for (int i = 0; i < 40; i++)
        cout << rng(re) << "#1 ";
    cout << endl;

    thread th1(proc1);
    thread th2(proc1);
    th1.join();
    th2.join();
    return 0;
}

int main()
{
/*     clock_t c0 = clock();
    time_t t0 = time(NULL);
    cout << c0 << endl;
    cout << t0 << endl;
    cout << CLOCKS_PER_SEC << endl;
    cout << (double)t0 + (double)c0 / CLOCKS_PER_SEC << endl;
*/
    auto t = std::chrono::high_resolution_clock::now();
    cout << t.time_since_epoch().count() << endl;
    
    return 0;
}