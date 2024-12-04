#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void swapArrays(int *&a, int *&b, int &na, int &nb);
int main()
{
    int na, nb;
    cin >> na;
    int *a = new int[na];
    f(i, 0, na) cin >> *(a + i);
    cin >> nb;
    int *b = new int[nb];
    f(i, 0, nb) cin >> *(b + i);
    swapArrays(a, b, na, nb);
    f(i, 0, na) cout << *(a + i) << " ";
    delete[] a;
    cout << endl;
    f(i, 0, nb) cout << *(b + i) << " ";
    delete[] b;
    return 0;
}
void swapArrays(int *&a, int *&b, int &na, int &nb)
{
    int *tmpptr = a;
    a = b;
    b = tmpptr;
    int tmpn = na;
    na = nb;
    nb = tmpn;
}