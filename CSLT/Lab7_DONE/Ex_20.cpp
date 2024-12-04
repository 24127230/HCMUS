#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int **rotateMatrix90Clockwise(int **a, int length, int width);
int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    f(i, 0, n)
    {
        a[i] = new int[m];
        f(j, 0, m) cin >> a[i][j];
    }
    int **ra = rotateMatrix90Clockwise(a, n, m);
    f(i, 0, m)
    {
        f(j, 0, n) cout << ra[i][j] << " ";
        cout << endl;
    }
    f(i, 0, n) delete[] a[i];
    delete[] a;
    f(i, 0, m) delete[] ra[i];
    delete[] ra;
    return 0;
}
int **rotateMatrix90Clockwise(int **a, int length, int width)
{
    int **b = new int *[width];
    f(i, 0, width)
    {
        b[i] = new int[length];
        f(j, 0, length) b[i][j] = a[length - 1 - j][i];
    }
    return b;
}