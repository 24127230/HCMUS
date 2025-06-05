#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    string rev_word = "";
    getline(cin, s);
    s += " ";
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (count)
            {
                rev_word = s.substr(i - count, count) + " " + rev_word;
            }
            count = 0;
        }
        else if (s[i] != ' ')
            count++;
    }
    cout << rev_word;
    return 0;
}