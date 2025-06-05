#include <iostream>
using namespace std;
void swap_char(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
void sort_string(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
            if (s[i] > s[j])
                swap_char(s[i], s[j]);
    }
}
int main()
{
    string s;
    cout << "Input a string: ";
    getline(cin, s);
    int i = 0;
    while (i < s.length())
    {
        while (s[i] == ' ')
            s.erase(i, 1);
        s[i] = tolower(s[i]);
        i++;
    }
    sort_string(s);
    s += ' ';
    int count = 0;
    for (int i = 0; i < s.length() - 1; i++)
        count = (s[i] != s[i + 1]) ? count + 1 : count;
    if (count == 26)
        cout << "This is a pangram.";
    else
        cout << "This is not a pangram.";
    return 0;
}