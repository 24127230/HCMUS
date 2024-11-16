#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void swap_num(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a[100][100], b[10005];
    int t = 0;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cin >> a[i][j];
            b[t] = a[i][j];
            t++;
        }
    }
    f(i, 0, n * m)
    {
        f(j, i + 1, n * m)
        {
            if (b[i] > b[j])
                swap_num(b[i], b[j]);
        }
    }
    t = 0;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            a[i][j] = b[t];
            t++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}