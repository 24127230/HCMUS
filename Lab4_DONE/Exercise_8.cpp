#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
const int N = 1e5 + 5;
int main()
{
    int n;
    cin >> n;
    int a[N], s[N];
    pair<int, int> f[N];
    f(i, 0, n)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    f[0].first = s[0];
    f[0].second = 0;
    int start, end, ma = 1;
    f(i, 1, n)
    {
        f[i].first = s[i];
        f[i].second = i;
        f(j, 0, i)
        {
            if (f[i].first < s[i] - s[j])
            {
                f[i].first = s[i] - s[j];
                f[i].second = j + 1;
            }
        }
        if (ma < f[i].first)
        {
            ma = f[i].first;
            start = f[i].second;
            end = i;
        }
    }
    f(i, start, end + 1) cout << a[i] << " ";
    return 0;
}