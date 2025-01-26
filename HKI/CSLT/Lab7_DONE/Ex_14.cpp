#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int **generateMatrix2(int *a, int *b, int na, int nb);
int main()
{
    int na, nb;

    cout << "Enter size, element of array a: ";
    cin >> na;
    int *a = new int[na];
    f(i, 0, na) cin >> *(a + i);

    cout << "Enter size, element of array b: ";
    cin >> nb;
    int *b = new int[nb];
    f(i, 0, nb) cin >> *(b + i);

    int **c = generateMatrix2(a, b, na, nb);

    delete[] a;
    delete[] b;

    f(i, 0, na)
    {
        f(j, 0, nb)
        {
            cout << *(*(c + i) + j) << " ";
        }
        cout << endl;
    }

    f(i, 0, na) delete[] *(c + i);
    delete[] c;

    return 0;
}
int **generateMatrix2(int *a, int *b, int na, int nb)
{
    int **matrix = new int *[na];

    f(i, 0, na)
    {
        *(matrix + i) = new int[nb];
        f(j, 0, nb)
        {
            *(*(matrix + i) + j) = *(a + i) * *(b + j);
        }
    }

    return matrix;
}