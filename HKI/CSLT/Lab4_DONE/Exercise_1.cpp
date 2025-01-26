#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int main()
{
    int n;
    int a[N];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max_odd = INT_MIN, min_even = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            min_even = (min_even > a[i]) ? a[i] : min_even;
        else
            max_odd = (max_odd < a[i]) ? a[i] : max_odd;
    }
    if (min_even != INT_MAX)
        cout << min_even << endl;
    else
        cout << "No even number\n";
    if (max_odd != INT_MIN)
        cout << max_odd << endl;
    else
        cout << "No odd number";
    return 0;
}