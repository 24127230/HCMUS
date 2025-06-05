#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    string z;
    cin >> n;
    cin >> z;
    if (n % 2 == 0)
    {
        cout << "No Solution";
        return 0;
    }
    unordered_map<char, int> charCount;
    for (auto i : z)
    {
        charCount[i]++;
    }
    int Oddchar = 0;
    char ExtraChar = '\0';
    for (auto it = charCount.begin(); it != charCount.end(); it++)
    {
        if (it->second % 2 != 0)
        {
            ExtraChar = it->first;
            Oddchar++;
        }
    }
    if(Oddchar > 1)
    {
        cout << "No Solution";
        return 0;
    }

    if (charCount[ExtraChar] > 1)
    {
        cout << "Multiple Solutions";
        return 0;
    }

    z.erase(z.find(ExtraChar), 1);
    z = z.substr(0, int(n / 2));
    cout << z;
    return 0;
}