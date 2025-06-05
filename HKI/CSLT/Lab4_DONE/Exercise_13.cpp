#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[100][100];
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    f(i, k - 1, n)
    {
        f(j, 0, m)
        {
            a[i][j] = a[i + 1][j];
        }
    }
    n--;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}