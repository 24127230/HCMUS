#include <iostream>
using namespace std;
int main()
{
    long long a, a_max = 0, a_min = INT_MAX;
    cin >> a;
    while (a)
    {
        if (a % 10 > a_max)
            a_max = a % 10;
        if (a % 10 < a_min)
            a_min = a % 10;
        a /= 10;
    }
    cout << a_min << " " << a_max;
}