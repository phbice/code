/* nest sope */
#include <iostream>

int reuse = 37; //global variable

int main()
{
    std::cout << reuse << std::endl;
    int reuse = 13; //local variable "reuse" hide global variable "reuse"
    std::cout << reuse << std::endl;
    std::cout << ::reuse << std::endl; //use global variable explicitly
    
    return 0;
}