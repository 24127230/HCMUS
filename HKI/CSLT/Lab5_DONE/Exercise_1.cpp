#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = 0, r = s.length() - 1;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
        {
            cout << "No";
            return 1;
        }
    }
    cout << "Yes";
    return 0;
}