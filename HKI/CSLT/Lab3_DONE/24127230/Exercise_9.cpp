#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a - b == 0)
        return a;
    if (a - b > 0)
        return gcd(a - b, b);
    return gcd(b - a, a);
}
int main()
{
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y);
    return 0;
}