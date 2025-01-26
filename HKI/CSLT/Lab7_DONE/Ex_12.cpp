#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int *mergeArrays(int *a, int *b, int na, int nb, int &nc);
int main()
{
    int na, nb;
    cin >> na;
    int *a = new int[na];
    f(i, 0, na) cin >> *(a + i);
    cin >> nb;
    int *b = new int[nb];
    f(i, 0, nb) cin >> *(b + i);
    int nc;
    int *c = mergeArrays(a, b, na, nb, nc);
    f(i, 0, nc) cout << *(c + i) << " ";
    delete[] c;
    return 0;
}
int *mergeArrays(int *a, int *b, int na, int nb, int &nc)
{
    nc = na + nb;
    int *c = new int[nc];
    int i = 0, j = 0;
    while (i + j < nc)
    {
        if (*(a + i) <= *(b + j))
        {
            *(c + i + j) = *(a + i);
            i++;
        }
        else
        {
            *(c + i + j) = *(b + j);
            j++;
        }
        while (i == na && j < nb)
        {
            *(c + i + j) = *(b + j);
            j++;
        }
        while (j == nb && i < na)
        {
            *(c + i + j) = *(a + i);
            i++;
        }
    }
    delete[] a;
    delete[] b;
    return c;
}