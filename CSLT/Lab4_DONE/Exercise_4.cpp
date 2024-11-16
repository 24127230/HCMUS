#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
const int N = 1e5 + 6;
void delete_num(int a[], int &n, int index)
{
    n--;
    f(i, index, n) a[i] = a[i + 1];
}
int main()
{
    int n, k;
    int a[N];
    cin >> n >> k;
    f(i, 0, n) cin >> a[i];
    int i = 0;
    while (i < n)
    {
        if (a[i] == k)
            delete_num(a, n, i);
        else
            i++;
    }
    f(i, 0, n) cout << a[i] << " ";
    return 0;
}