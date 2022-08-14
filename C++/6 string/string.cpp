/* string */
#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str;
    cout << "Input something... >";
    getline(cin, str);
    
    for (char c : str)
        cout << (char)toupper(c);
    
    cout << endl;
    return 0;
}