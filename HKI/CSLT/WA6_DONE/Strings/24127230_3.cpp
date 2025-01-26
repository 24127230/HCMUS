#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Input a string: ";
    getline(cin, s);
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
        if (s[i] == ' ')
        {
            count = 0;
        }
        else
        {
            count++;
            if (count == 1)
                s[i] = toupper(s[i]);
        }
    }
    cout << s;
    return 0;
}