#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int *concatenateArrays(int *a, int *b, int na, int nb);
int main()
{
    int na, nb;
    cin >> na;
    int *a = new int[na];
    f(i, 0, na) cin >> *(a + i);
    cin >> nb;
    int *b = new int[nb];
    f(i, 0, nb) cin >> *(b + i);
    int *ab = concatenateArrays(a, b, na, nb);
    f(i, 0, na + nb) cout << *(ab + i) << " ";
    delete[] ab;
    return 0;
}
int *concatenateArrays(int *a, int *b, int na, int nb)
{
    int *ptr = new int[na + nb];
    f(i, 0, na + nb)
    {
        *(ptr + i) = (i < na) ? *(a + i) : *(b + i - na);
    }
    delete[] a;
    delete[] b;
    return ptr;
}