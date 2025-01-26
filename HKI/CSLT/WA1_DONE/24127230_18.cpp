#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    int year = 2024;
    int cnt = 0;
    while (cnt < 20)
    {
        year++;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            cnt++;
            cout << year << '\n';
        }
    }
    return 0;
}