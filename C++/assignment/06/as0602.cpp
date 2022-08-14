/*
 �жϸ��������Ƿ�Ϊ������
 
    ����
    2019-4-29 20:52
*/

#include <iostream>

bool is_palindoromic(unsigned int original)
{
    unsigned int reversed = 0;
    unsigned int t = original;
    while (t != 0)
    {
        reversed = reversed * 10 + t % 10;
        t /= 10;
    }
    
    return reversed == original;
}

int main()
{
    unsigned int digit;
    std::cout << "����һ�����������ж����Ƿ�Ϊ������\n�����룺";
    std::cin >> digit;

    if (is_palindoromic(digit))
        std::cout << digit << " �ǻ�����" << std::endl;
    else
        std::cout << digit << " ���ǻ�����" << std::endl;

    return 0;
}