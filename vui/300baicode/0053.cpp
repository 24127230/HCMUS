#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
bool isprime(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    vector<int> a;
    int num;
    while (cin >> num)
    {
        a.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int maxprime = INT_MIN;
    for (int i : a)
    {
        if (isprime(i))
            maxprime = (maxprime > i) ? maxprime : i;
    }
    if (maxprime == INT_MIN)
        cout << '-';
    else
        cout << maxprime;
    return 0;
}