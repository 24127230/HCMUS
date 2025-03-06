#include <iostream>
#include <string>
using namespace std;
void NormalizeParagraph(string &s)
{
    while (s[0] == ' ')
    {
        s.erase(0, 1);
    }
    while (s[s.length() - 1] == ' ')
    {
        s.erase(s.length() - 1, 1);
    }
    for (int i = 1; i < s.length();)
    {
        if (s[i - 1] == ' ')
        {
            if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z')
                i++;
            else
                s.erase(i - 1, 1);
        }
        else
            i++;
    }
}
int countword(string &s)
{
    if (s.empty())
        return 0;
    int count = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            count++;
    }
    return count;
}
string longestword(string s)
{
    s += ' ';
    int end = 0;
    int maxlength = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z')
        {
            count++;
        }
        else
        {
            if (count > maxlength)
            {
                maxlength = count;
                end = i;
            }
            count = 0;
        }
    }
    return s.substr(end - maxlength, maxlength);
}
int main()
{
    string s;
    getline(cin, s);
    NormalizeParagraph(s);
    cout << "Normalized paragraph:\n"
         << s << '\n';
    cout << "Word count: " << countword(s) << '\n';
    cout << "Longest word: " << longestword(s);
    return 0;
}