#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, ans = 1;
    int k;
    cin >> x >> k;
    int factorial[k + 1];
    factorial[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        factorial[i] = i * factorial[i - 1];
        ans += pow(x, i) / factorial[i];
    }
    cout << ans;
}