/*
 百鸡百钱问题
 
    彭寒冰
    2019-3-31 15:26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int hen, chick;
    
    cout << setw(6) << left << "公鸡"
         << setw(6) << left << "母鸡"
         << "小鸡\n----------------" << endl;
    
    for (chick = 0; chick/3 <= 100; chick+=3)
        for (hen = 0; 3*hen + chick/3 <= 100; hen++)
            if ( 5*(100-chick-hen) + 3*hen + chick/3 == 100)
                cout << setw(6) << left << 100-chick-hen
                     << setw(6) << left << hen
                     << chick << endl;
    
    return 0;
}
