#include <iostream>
using namespace std;
void copy_array(int *p1, int *p2, int n);
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int *b = new int[n];
    copy_array(b, a, n);
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    delete[] a;
    delete[] b;
    return 0;
}
void copy_array(int *p1, int *p2, int n)
{
    int *end = p2 + n;
    while (p2 != end)
        *(p1++) = *(p2++);
}