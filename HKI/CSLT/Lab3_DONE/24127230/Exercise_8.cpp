#include <iostream>
#define ll long long
using namespace std;
ll sumDigits(ll x)
{
    if (x < 10)
        return x;
    return x % 10 + sumDigits(x / 10);
}
int main()
{
    ll n;
    cin >> n;
    cout << sumDigits(n);
    return 0;
}