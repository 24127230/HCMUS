#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Num of element: ";
    cin >> n;
    // if(!n){
    //     cout << "\n";
    //     return 0;
    // }
    cout << "First 3 element: ";
    int *a = new int[n];
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < n; i++)
    {
        if (i > 2)
            a[i] = a[i - 1] + a[i - 2] + a[i - 3];
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}