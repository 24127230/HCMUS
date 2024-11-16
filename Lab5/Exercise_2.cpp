#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int max_lenght = 0, length = 0;
    string max_length_word;
    int maxbegin, begin = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (max_lenght < length)
            {
                max_lenght = length;
                maxbegin = begin;
            }
            begin = i + 1;
            length = 0;
        }
        else
        {
            length++;
        }
    }
    max_length_word.append(s, maxbegin, max_lenght);
    cout << max_length_word;
}