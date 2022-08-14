#include <iostream>

int len(char * str)
{
    int i;
    for (i = 0; str[i] != 0; i++);
    return i;
}

bool match(char * sub_str, char * str)
{
    int i;
    for (i = 0; sub_str[i] != 0; i++)
        if (sub_str[i] != str[i])
            return false;
    return true;
}

int find(char * sub_str, char * str)
{
    int index;
    for (index = 0; index <= len(str) - len(sub_str); index++)
        if ( match(sub_str, str + index) )
            return index;
    return -1;
}

int main()
{
    char str[128];
    char sub_str[128];
    int index;
    
    std::cout << "请输入字符串：";
    std::cin.getline(str, 128);
    std::cout << "请输入子串：";
    std::cin.getline(sub_str, 128);
    
    index = find(sub_str, str);
    if (index == -1)
        std::cout << sub_str << "不是" << str << "的子串。" << std::endl;
    else
        std::cout << index << std::endl;
    return 0;
}