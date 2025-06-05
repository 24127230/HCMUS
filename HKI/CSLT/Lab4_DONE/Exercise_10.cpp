#include <iostream>
#include <algorithm>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
const int N = 1e5 + 5;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[N], b[N];
    f(i, 0, n) cin >> a[i];
    f(i, 0, m) cin >> b[i];
    f(i, n, m + n)
        a[i] = b[i - n];
    sort(a, a + n + m);
    f(i, 0, n + m) cout << a[i] << " ";
    return 0;
}