#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cout << "Input a string: ";
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    int l = 0, r = s.length() - 1;
    while (l < r)
    {
        while (s[l] == ' ')
            l++;
        while (s[r] == ' ')
            r--;
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
        {
            cout << "This is not a palindrome.";
            return 1;
        }
    }
    cout << "This is a palindrome.";
    return 0;
}