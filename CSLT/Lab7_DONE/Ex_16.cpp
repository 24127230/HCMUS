#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int **transposeMatrix(int **a, int length, int width);
int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    f(i, 0, n)
    {
        *(a + i) = new int[m];
        f(j, 0, m)
        {
            cin >> *(*(a + i) + j);
        }
    }

    int **at = transposeMatrix(a, n, m);

    f(i, 0, n) delete[] *(a + i);
    delete[] a;

    f(i, 0, m)
    {
        f(j, 0, n)
        {
            cout << at[i][j] << " ";
        }
        cout << endl;
        delete[] *(at + i);
    }
    delete[] at;

    return 0;
}
int **transposeMatrix(int **a, int length, int width)
{
    int **b = new int *[width];
    f(i, 0, width)
    {
        *(b + i) = new int[length];
        f(j, 0, length)
        {
            b[i][j] = a[j][i];
        }
    }
    return b;
}