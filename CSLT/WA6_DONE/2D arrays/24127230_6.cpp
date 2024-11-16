#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void input_matrix(int x[][100], int n)
{
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            cin >> x[i][j];
        }
    }
}
void element_wise_product()
{
    int n;
    cout << "Enter size of two matrices: ";
    cin >> n;
    int a[100][100], b[100][100], ab[100][100];
    cout << "Input the first two-dimensional array\n";
    input_matrix(a, n);
    cout << "Input the first two-dimensional array\n";
    input_matrix(b, n);
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            ab[i][j] = a[i][j] * b[i][j];
        }
    }
    cout << "The element-wise product of two matrices is\n";
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            cout << ab[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    element_wise_product();
    return 0;
}