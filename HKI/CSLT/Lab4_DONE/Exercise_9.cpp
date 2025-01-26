#include <iostream>
#include <algorithm>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
const int N = 1e5 + 5;
int main()
{
    int n;
    cin >> n;
    int a[N];
    f(i, 0, n) cin >> a[i];
    sort(a, a + n);
    int count = 0;
    f(i, 0, n)
    {
        count++;
        if (a[i] != a[i + 1] || i == n)
        {
            cout << a[i] << ": " << count << endl;
            count = 0;
        }
    }
    return 0;
}
