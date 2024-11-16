#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[N];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    int i = 0;
    while (k != 0)
    {
        if (a[i] != a[i - 1])
            k--;
        i++;
        if (i == n)
        {
            cout << "Not found";
            return 1;
        }
    }
    cout << a[i - 1];
    return 0;
}