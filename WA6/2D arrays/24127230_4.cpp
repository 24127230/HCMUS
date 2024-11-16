#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void transpose_matrix()
{
    int a_column, a_row;
    cout << "Enter row, column: ";
    cin >> a_row >> a_column;
    int a[100][100], b[100][100];
    cout << "Input a two-dimesional array\n";
    f(i, 0, a_row)
    {
        f(j, 0, a_column)
        {
            cin >> a[i][j];
        }
    }
    int b_row = a_column, b_column = a_row;
    f(i, 0, b_row)
    {
        f(j, 0, b_column)
        {
            b[i][j] = a[j][i];
        }
    }
    cout << "The transpose of the given matrix is\n";
    f(i, 0, b_row)
    {
        f(j, 0, b_column)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    transpose_matrix();
    return 0;
}