#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void swapRows(int **&a, int length, int width, int row1, int row2);
void swapColumns(int **&a, int length, int width, int col1, int col2);
int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    f(i, 0, n)
    {
        a[i] = new int[m];
        f(j, 0, m)
        {
            cin >> a[i][j];
        }
    }

    int row1, row2, col1, col2;
    cout << "Enter two row: ";
    cin >> row1 >> row2;
    cout << "Enter two column: ";
    cin >> col1 >> col2;

    swapRows(a, n, m, row1, row2);
    swapColumns(a, n, m, col1, col2);

    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    f(i, 0, n) delete[] a[i];
    delete[] a;
    return 0;
}
void swapRows(int **&a, int length, int width, int row1, int row2)
{
    int *tmp = *(a + row1);
    *(a + row1) = *(a + row2);
    *(a + row2) = tmp;
}
void swapColumns(int **&a, int length, int width, int col1, int col2)
{
    f(i, 0, length)
    {
        int tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}