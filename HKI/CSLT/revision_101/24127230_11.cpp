#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[256];
    cin.getline(s, 256);
    int sum = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if ((strlen(s) % 2 + i) % 2 == 0)
        {
            s[i] = (s[i] - '0') * 2 - ((s[i] >= '5') ? 9 : 0) + '0';
        }
        sum += s[i] - '0';
    }
    cout << ((sum % 10 == 0) ? "Valid credit card number" : "Invalid credit card number");
    return 0;
}