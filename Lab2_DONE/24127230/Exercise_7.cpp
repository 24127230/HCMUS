#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a;
    cin >> a;
    if (a == 0 || a == 1)
    {
        cout << "Not Prime";
        return 1;
    }
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0)
        {
            cout << " Not Prime";
            return 1;
        }
    cout << "Prime";
    return 0;
}