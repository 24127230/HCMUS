#include <iostream>
using namespace std;
bool happynum(long long n)
{
    // cout << n << endl;
    if (n == 1)
        return 1;
    if (n == 4)
        return 0;
    long long sum = 0;
    while (n > 0)
    {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return happynum(sum);
}
int main()
{
    long long n;
    cin >> n;
    if (happynum(n))
        cout << "yes";
    else
        cout << "no";
    return 0;
}
// 1
// 4