#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, sum = 1;
    cin >> a;
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0)
            sum += i + a / i;
    if (sum == a)
        cout << "Perfect";
    else
        cout << "Not Perfect";
    return 0;
}