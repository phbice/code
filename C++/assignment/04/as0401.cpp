/*
 �ټ���Ǯ����
 
    ����
    2019-3-31 15:26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int hen, chick;
    
    cout << setw(6) << left << "����"
         << setw(6) << left << "ĸ��"
         << "С��\n----------------" << endl;
    
    for (chick = 0; chick/3 <= 100; chick+=3)
        for (hen = 0; 3*hen + chick/3 <= 100; hen++)
            if ( 5*(100-chick-hen) + 3*hen + chick/3 == 100)
                cout << setw(6) << left << 100-chick-hen
                     << setw(6) << left << hen
                     << chick << endl;
    
    return 0;
}
