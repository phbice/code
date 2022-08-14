/* vector */

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> strings(10, "hi");
    for (string string_out : strings)
        cout << string_out << endl;

    return 0;
}
