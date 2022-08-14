/*
 100元钞票 买3元、4元、5元的商品
 求有多少种买法可以刚好花完100元

    彭寒冰
    2019-3-31 15:38
*/

#include <iostream>
using namespace std;

int main()
{
    int x3, x4;
    int count = 0;
    
    for (x3 = 0; 3*x3 <= 100; x3++)
        for (x4 = 0; 3*x3 + 4*x4 <= 100; x4++)
            if ((100 - 3*x3 - 4*x4) % 5 == 0)
                count++;
    cout << count << endl;
    
    return 0;
}
