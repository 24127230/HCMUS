#include <iostream>
using namespace std;
int *copyArray(int *arr, int n);
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> *(a + i);
    int *a2 = copyArray(a, n);
    delete[] a;
    for (int i = 0; i < n; i++)
        cout << *(a2 + i) << " ";
    delete[] a2;
    return 0;
}
int *copyArray(int *arr, int n)
{
    int *copya = new int[n];
    for (int i = 0; i < n; i++)
        *(copya + i) = *(arr + i);
    return copya;
}