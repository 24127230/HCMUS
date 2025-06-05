#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Input number of data values in the set: ";
    cin >> n;
    int *a = new int[n];
    cout << "Input value: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *max = a;
    for (int i = 1; i < n; i++)
    {
        if (*max < a[i])
            max = a + i;
    }
    cout << "Value of the pointer that points to the max value: " << max << endl;
    cout << "The value dereferenced by that pointer: " << *max;
    delete max;
    delete[] a;
    return 0;
}