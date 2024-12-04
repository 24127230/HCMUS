#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
bool multiply2Matrices(int **a, int **b, int lengtha, int widtha,
                       int lengthb, int widthb, int **&result);
int main()
{
    cout << "Enter first matrix: ";
    int lengtha, widtha;
    cin >> lengtha >> widtha;
    int **a = new int *[lengtha];
    f(i, 0, lengtha)
    {
        a[i] = new int[widtha];
        f(j, 0, widtha) cin >> a[i][j];
    }
    cout << "Enter second matrix: ";
    int lengthb, widthb;
    cin >> lengthb >> widthb;
    int **b = new int *[lengthb];
    f(i, 0, lengthb)
    {
        b[i] = new int[widthb];
        f(j, 0, widthb) cin >> b[i][j];
    }

    int **ab = nullptr;
    if (multiply2Matrices(a, b, lengtha, widtha, lengthb, widthb, ab))
    {
        cout << "Result:\n";
        f(i, 0, lengtha)
        {
            f(j, 0, widthb) cout << ab[i][j] << " ";
            cout << endl;
            delete[] ab[i];
        }
        delete[] ab;
    }
    else
        cout << "false";

    f(i, 0, lengtha) delete[] a[i];
    delete[] a;
    f(i, 0, lengthb) delete[] a[i];
    delete[] b;

    return 0;
}
bool multiply2Matrices(int **a, int **b, int lengtha, int widtha,
                       int lengthb, int widthb, int **&result)
{
    if (widtha != lengthb)
        return 0;
    result = new int *[lengtha];
    f(i, 0, lengtha)
    {
        result[i] = new int[widthb];
        f(j, 0, widthb)
        {
            result[i][j] = 0;
            f(z, 0, widtha)
            {
                result[i][j] += a[i][z] * b[z][j];
            }
        }
    }
    return 1;
}