#include <iostream>
using namespace std;
const int N = 1e5 + 6;
#define f(a, b, c) for (int a = b; a < c; a++)
void swp(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void sort_asc(int a[], int n)
{
    f(i, 0, n - 1)
    {
        f(j, i + 1, n)
        {
            if (a[i] > a[j])
                swp(a[i], a[j]);
        }
    }
}
int main()
{
    int n;
    int a[N];
    cin >> n;
    f(i, 0, n)
    {
        cin >> a[i];
    }
    sort_asc(a, n);
    f(i, 0, n) cout << a[i] << " ";
    return 0;
}