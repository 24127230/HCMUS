#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void sum_lower_tria_matrix()
{
    int n, m;
    cout << "Enter row, column: ";
    cin >> n >> m;
    int a[100][100];
    float k = (m - 1) / (n - 1);
    int sum;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cin >> a[i][j];
            if (k * i - j > 0)
                sum += a[i][j];
        }
    }
    cout << "The sum is " << sum;
}
int main()
{
    sum_lower_tria_matrix();
    return 0;
}