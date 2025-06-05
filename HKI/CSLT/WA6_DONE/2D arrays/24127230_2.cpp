#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void square_matrix()
{
    int n;
    cin >> n;
    int a[100][100];
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            a[i][j] = (i > j) ? i - j : j - i;
        }
    }
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}
int main()
{
    square_matrix();
    return 0;
}