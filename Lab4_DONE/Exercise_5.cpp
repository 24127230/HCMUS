#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
const int N = 1e5 + 5;
void swp(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int n;
    cin >> n;
    int a[N];
    f(i, 0, n) cin >> a[i];
    f(i, 0, n / 2) swp(a[i], a[n - 1 - i]);
    f(i, 0, n) cout << a[i] << " ";
    return 0;
}