#include <iostream>
using namespace std;
int main()
{
    int n, x, y;
    cout << "n = ";
    cin >> n;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    if (n % x == 0 && n % y == 0)
        cout << "true because " << n << " is divisible by " << x << " and " << y;
    else if (n % x != 0 && n % y != 0)
        cout << "false because " << n << " is neither divisible by " << x << " nor " << y;
    else if (n % x == 0)
        cout << "false because " << n << " is not divisible by " << y;
    else
        cout << "false because " << n << " is not divisible by " << x;
    return 0;
}