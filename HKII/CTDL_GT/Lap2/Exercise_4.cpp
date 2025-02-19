#include <iostream>
using namespace std;

bool IsIncreasingArray(int *a, int n)
{
    if (--n == 0)
        return 1;
    if (*a >= *(a + 1)) return 0;
    return IsIncreasingArray(a + 1, n);
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if(IsIncreasingArray(a, n)) cout << "Yes";
    else cout << "No";
    delete[] a;
    return 0;
}