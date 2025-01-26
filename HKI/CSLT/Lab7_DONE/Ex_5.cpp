#include <iostream>
using namespace std;
int *findMax(int *arr, int n);
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> *(a + i);
    int *Max = findMax(a, n);
    cout << *Max;
    delete[] a;
    return 0;
}
int *findMax(int *arr, int n)
{
    int *ptr = arr;
    for (int i = 0; i < n; i++)
        ptr = (*(arr + i) > *ptr) ? arr + i : ptr;
    return ptr;
}