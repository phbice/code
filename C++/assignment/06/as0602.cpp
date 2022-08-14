/*
 判断给定整数是否为回文数
 
    彭寒冰
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
    std::cout << "输入一个正整数，判断其是否为回文数\n请输入：";
    std::cin >> digit;

    if (is_palindoromic(digit))
        std::cout << digit << " 是回文数" << std::endl;
    else
        std::cout << digit << " 不是回文数" << std::endl;

    return 0;
}