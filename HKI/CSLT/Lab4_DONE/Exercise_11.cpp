#include <iostream>
#include <cmath>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
const int N = 100;
int main()
{
    int notprime[100000] = {1, 1};
    f(i, 2, sqrt(100000) + 1) if (notprime[i] == 0)
    {
        f(j, 2, sqrt(100000) / i)
            notprime[j * i] = 1;
    }
    int n, m;
    int a[N][N];
    cin >> n >> m;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    int max_prime = 0, min_prime = 100000;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            if (!notprime[a[i][j]])
            {
                max_prime = (max_prime < a[i][j]) ? a[i][j] : max_prime;
                min_prime = (min_prime > a[i][j]) ? a[i][j] : min_prime;
            }
        }
    }
    cout << min_prime << " " << max_prime;
    return 0;
}