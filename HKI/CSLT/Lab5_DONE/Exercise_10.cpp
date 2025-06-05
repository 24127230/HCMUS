#include <iostream>
#include <string>
using namespace std;
bool isDifferent(string s, int begin1, int count1, int begin2, int count2)
{
    if (count1 != count2)
        return 1;
    for (int i = 0; i < count1; i++)
        if (tolower(s[i + begin1]) != tolower(s[i + begin2]))
            return 1;
    return 0;
}
int main()
{
    string s;
    getline(cin, s);
    s += ' ';
    int i = 0;
    int res = 0;
    while (i < s.length())
    {
        int count = 0;
        while (s[i] != ' ')
        {
            count++;
            i++;
        }
        if (count)
        {
            int j = i + 1, same = 0;
            while (j < s.length())
            {
                int countj = 0;
                while (s[j] != ' ')
                {
                    countj++;
                    j++;
                }
                if (!isDifferent(s, i - count, count, j - countj, countj))
                    same = 1;
                j++;
            }
            if (!same)
                res++;
        }
        i++;
    }
    cout << res;
    return 0;
}