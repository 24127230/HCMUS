#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    while (s.find("  ") < s.length())
        s.erase(s.find("  ") + 1, 1);
    while (s[0] == ' ')
        s.erase(0, 1);
    while (s[s.length() - 1] == ' ')
        s.erase(s.length() - 1, 1);
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == ' ')
            if (tolower(s[i + 1]) < 'a' || tolower(s[i + 1]) > 'z')
                s.erase(i, 1);
        i++;
    }
    cout << s;
    return 0;
}