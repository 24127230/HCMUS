#include <iostream>
using namespace std;
const int N = 1e5 + 5;
#define f(a, b, c) for (int a = b; a < c; a++)
int main()
{
    int n;
    int a[N];
    cin >> n;
    f(i, 0, n) cin >> a[i];
    bool notincrease = 1, notdecrease = 1;
    f(i, 0, n - 1)
    {
        if (a[i] > a[i + 1])
            notdecrease = 0;
        if (a[i] < a[i + 1])
            notincrease = 0;
    }
    if (!notincrease && !notdecrease)
        cout << "Regular\n";
    else
    {
        if (notincrease)
            cout << "Not increasing\n";
        if (notdecrease)
            cout << "Not decreasing\n";
    }
    return 0;
}