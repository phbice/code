/*
 �ϴ����˹����Ԫ��
 
    ����
    2019-3-31 15:48
*/

#include <iostream>
using namespace std;

int main()
{
    int side1, side2, hypotenuse;
    
    cout << "�ϴ����˹��Ԫ��" << endl;
    
    for (side1 = 1; side1 <= 500; side1++)
        for (side2 = side1; side2 <= 500; side2++)
            for (hypotenuse = side2; hypotenuse <=500; hypotenuse++)
                if (side1*side1 + side2*side2 == hypotenuse*hypotenuse)
                {
                    cout << "(" << side1 << ", " << side2
                         << ", " << hypotenuse << ")" << endl;
                    break;
                }
    return 0;
}