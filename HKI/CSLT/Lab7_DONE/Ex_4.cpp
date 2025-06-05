#include <iostream>
using namespace std;
void printArray(int *a, int n);
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> *(a + i);
    }
    printArray(a, n);
    delete[] a;
    return 0;
}
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}