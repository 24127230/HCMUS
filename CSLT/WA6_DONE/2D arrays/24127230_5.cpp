#include <iostream>
#include <cmath>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void trace_determinant()
{
    int n = 3;
    cout << "Input a two_dimensional array\n";
    int a[100][100];
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            cin >> a[i][j];
        }
    }
    int trace, determinant, d1 = 1, d2 = 1, d3 = 1, d4 = 1, d5 = 1, d6 = 1;
    f(i, 0, n) // cal by rule of Sarrus
    {
        f(t, 0, n + n - 1)
        {
            int j = (t >= 3) ? t - 3 : t;
            switch (i - t)
            {
            case 0:
                trace += a[i][j];
                d1 *= a[i][j];
                break;
            case -1:
                d2 *= a[i][j];
                break;
            case -2:
                d3 *= a[i][j];
                break;
            default:
                break;
            }
            switch (i + t)
            {
            case 2:
                d4 *= a[i][j];
                break;
            case 3:
                d5 *= a[i][j];
                break;
            case 4:
                d6 *= a[i][j];
                break;
            default:
                break;
            }
        }
    }
    determinant = d1 + d2 + d3 - d4 - d5 - d6;
    cout << "The trace of the given matix is " << trace << endl;
    cout << "The determinant of the given matrix is " << determinant;
}
int main()
{
    trace_determinant();
    return 0;
}