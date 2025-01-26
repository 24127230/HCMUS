#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
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
        if (count)
            cout << count << ' ';
        i++;
    }
    return 0;
}