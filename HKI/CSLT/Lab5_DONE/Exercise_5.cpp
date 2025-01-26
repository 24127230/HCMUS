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
        {
            if (s[i] > s[j])
                swap_char(s[i], s[j]);
        }
    }
}
int main()
{
    string s;
    getline(cin, s);
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    for (int i = 0; i < s.length(); i++)
        while (s[i] < 'a' || s[i] > 'z')
            s.erase(i, 1);
    sort_string(s);
    cout << s << endl;
    for (int i = 0; i < s.length(); i++)
    {
        count++;
        if (i == s.length() - 1)
            cout << s[i] << ":" << count;
        else if (s[i] != s[i + 1])
        {
            cout << s[i] << ":" << count << ", ";
            count = 0;
        }
    }
    return 0;
}