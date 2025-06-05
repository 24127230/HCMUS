#include <iostream>
#include <string>
using namespace std;

bool IsPalindromeString(string s)
{
    if(s.length()<= 1)return 1;
    if(s[0] != s[s.length() - 1])return 0;
    return IsPalindromeString(s.substr(1,s.length() - 2));
}

int main()
{
    string s;
    getline(cin, s);
    if (IsPalindromeString(s)) cout << "Yes";
    else cout << "No";
    return 0;
}