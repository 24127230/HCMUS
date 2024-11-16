#include <iostream>
#include <cmath>
using namespace std;
int isPerfectSquare(int x)
{
    int sqx = sqrt(x);
    if (x == sqx * sqx)
        return 1;
    return 0;
}
int main()
{
    int n;
    cin >> n;
    if (isPerfectSquare(n))
        cout << "true";
    else
        cout << "false";
    return 0;
}