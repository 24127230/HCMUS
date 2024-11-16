#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void convert()
{
    int n, m;
    cout << "Column: ";
    cin >> m;
    cout << "Row: ";
    cin >> n;
    int a[100][100], b[10000];
    cout << "Input a two-dimensional array:\n";
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cout << "element - " << i << "," << j << ": ";
            cin >> a[i][j];
            b[i * n + j] = a[i][j];
        }
    }
    int b_size = n * m;
    cout << "The output one-dimensional array is: ";
    f(i, 0, b_size)
    {
        cout << b[i] << " ";
    }
}
int main()
{
    convert();
    return 0;
}
