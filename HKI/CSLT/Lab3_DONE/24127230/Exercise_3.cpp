#include <iostream>
using namespace std;
int sumUpToN(int x)
{
    if (x == 1)
        return 1;
    return x + sumUpToN(x - 1);
}
int main()
{
    int n, s;
    cin >> n;
    s = sumUpToN(n);
    cout << s;
    return 0;
}