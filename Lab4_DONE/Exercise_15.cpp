#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int main()
{
    int n, m;
    int a[100][100];
    cin >> n >> m;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    int rotate_n = m, rotate_m = n;
    int rotate_a[100][100];
    f(i, 0, rotate_n)
    {
        f(j, 0, rotate_m)
        {
            rotate_a[i][j] = a[rotate_m - j - 1][i];
        }
    }
    f(i, 0, rotate_n)
    {
        f(j, 0, rotate_m)
        {
            cout << rotate_a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}