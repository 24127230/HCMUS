#include <iostream>
#include <string>
using namespace std;
void swap_word(string &s, int begin1, int count1, int begin2, int count2)
{
    string s1 = s.substr(begin1, count1);
    string s2 = s.substr(begin2, count2);
    // cout << s1 << endl;
    // cout << s2 << endl;
    s.erase(begin1, count1);
    s.insert(begin1, s2);
    s.erase(begin2 - count1 + count2, count2);
    s.insert(begin2 - count1 + count2, s1);
    cout << s << endl;
}
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
        sub_s = s.substr(i - count, count);
        if (count)
        {
            int j = i + 1;
            while (j < s.length())
            {
                int countj = 0;
                while (s[j] != ' ')
                {
                    countj++;
                    j++;
                }
                if (s[i - count] > s[j - countj])
                {
                    swap_word(s, i - count, count, j - countj, countj);
                    i = i + countj - count;
                    count = countj;
                }
                j++;
            }
        }
        i++;
    }
    cout << s;
    return 0;
}
// the quick brown fox