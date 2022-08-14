/* reference */

#include <iostream>

int main()
{
    int i = 107;
    int &ref = i; //"ref" refers to i, it's an alias of id
    std::cout << i << std::endl;
    ref += 213; //operations on ref are actually operations on i
    std::cout << ref << ' ' << i << std::endl;
    
    return 0;
}