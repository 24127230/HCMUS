#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s, rev_s;
    getline(cin, s);
    s += ' ';
    int i = 0;
    while (i < s.length())
    {
        int count = 0;
        while (s[i] != ' ')
        {
            count++;
            i++;
        }
        if (count != 0)
            rev_s = s.substr(i - count, count) + ' ' + rev_s;
        i++;
    }
    cout << rev_s;
    return 0;
}