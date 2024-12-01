#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int **concatenate2MatricesH(int **a, int **b, int length, int width);
int **concatenate2MatricesV(int **a, int **b, int length, int width);
int main()
{
    int n, m;
    cout << "Enter length, width for two matrices: ";
    cin >> n >> m;
    cout << "First matrix:\n";
    int **a = new int *[n];
    f(i, 0, n)
    {
        a[i] = new int[m];
        f(j, 0, m) cin >> a[i][j];
    }
    cout << "Second matrix:\n";
    int **b = new int *[n];
    f(i, 0, n)
    {
        b[i] = new int[m];
        f(j, 0, m) cin >> b[i][j];
    }

    int **h = concatenate2MatricesH(a, b, n, m);
    cout << "A new matrix resulting from horizontal concatenation of a and b:\n";
    f(i, 0, n)
    {
        f(j, 0, m * 2) cout << h[i][j] << " ";
        cout << endl;
        delete[] h[i];
    }
    delete[] h;

    int **v = concatenate2MatricesV(a, b, n, m);
    cout << "A new matrix resulting from vertical concatenation of a and b:\n";
    f(i, 0, n * 2)
    {
        f(j, 0, m) cout << v[i][j] << " ";
        cout << endl;
        delete[] v[i];
    }
    delete[] v;

    f(i, 0, n)
    {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}
int **concatenate2MatricesH(int **a, int **b, int length, int width)
{
    int **c = new int *[length];
    f(i, 0, length)
    {
        c[i] = new int[width * 2];
        f(j, 0, width * 2) c[i][j] = (j < width) ? a[i][j] : b[i][j - width];
    }
    return c;
}
int **concatenate2MatricesV(int **a, int **b, int length, int width)
{
    int **c = new int *[length * 2];
    f(i, 0, length * 2)
    {
        c[i] = new int[width];
        f(j, 0, width * 2) c[i][j] = (i < length) ? a[i][j] : b[i - length][j];
    }
    return c;
}