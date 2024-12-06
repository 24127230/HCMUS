#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int l = 0;
    int r = s.length() - 1;
    while (l <= r)
    {
        if (s[l] != s[r])
        {
            cout << "NO";
            return 0;
        }
        l++;
        r--;
    }
    cout << "YES";
    return 0;
}