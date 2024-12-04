#include <iostream>
using namespace std;
void inputArray(int *&a, int &n);
int main()
{
    int n;
    int *a = nullptr;
    inputArray(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
    delete[] a;
    return 0;
}
void inputArray(int *&a, int &n)
{
    cout << "Size: ";
    cin >> n;
    a = new int[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(a + i);
    }
}
