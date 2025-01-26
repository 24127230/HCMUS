#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
            count++;
    }
    if (!count)
        cout << "NO SOLUTION";
    else
    {
        int *p = a;
        while (p < a + n)
        {
            if (*p % 2 != 0)
                cout << *p << " ";
            p++;
        }
    }

    delete[] a;
    return 0;
}