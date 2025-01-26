#include <iostream>
#include <cstring>
using namespace std;
bool password(char a[])
{
    if (strlen(a) < 8)
        return 0;
    bool r1 = 0, r2 = 0, r3 = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            r1 = 1;
        if (a[i] >= 'a' && a[i] <= 'z')
            r2 = 1;
        if (a[i] >= '0' && a[i] <= '9')
            r3 = 1;
        if (r1 && r2 && r3)
            return 1;
    }
    // cout << r1 << " " << r2 << " " << r3 << endl;
    return 0;
}
int main()
{
    char s[256];
    cin.getline(s, 256);
    cout << password(s) << endl;
    return 0;
}