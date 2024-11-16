#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void do_something()
{
    int n, m;
    cout << "Enter column, row: ";
    cin >> m >> n;
    int a[100][100];
    cout << "Input a two-dimensional array \n";
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    if (n != m)
        cout << "Is not a square matrix";
    else
    {
        bool sym_matrix = 1, id_matrix = 1;
        f(i, 0, n)
        {
            f(j, i, m)
            {
                if (a[i][j] != a[j][i])
                {
                    sym_matrix = 0;
                    id_matrix = 0;
                    i = n; // break 2 loop
                    j = m;
                }
                else if ((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0))
                {
                    id_matrix = 0;
                    i = n; // break 2 loop
                    j = m;
                }
            }
        }
        cout << "It is a square matrix. ";
        if (sym_matrix)
        {
            cout << "Is a symmetric matrix. ";
            if (id_matrix)
                cout << "Is  an identity matrix. ";
        }
    }
}
int main()
{
    do_something();
    return 0;
}