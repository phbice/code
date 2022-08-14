/* subscript */
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int printhex(int input)
{
    string hexdigits("0123456789ABCDEF");
    if (input != 0)
    {
        printhex(input / 16);
        cout << hexdigits[input % 16];
    }
    
    return 0;
}

int main()
{
    int input;
    cout << "Input a Interger >";
    cin >> input;
    printhex(input);
    cout << endl;
    
    return 0;
}