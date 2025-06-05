#include <iostream>
#include <string>
using namespace std;
string ReverseString (string s)
{
    if(s.length() == 1) return s.substr(0, 1);
    return ReverseString(s.substr(1, s.length() - 1)) + s.substr(0, 1);
}
int main()
{
    string s;
    getline(cin, s);
    cout << ReverseString(s);
    return 0;
}

