#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Input the number: ";
    cin >> x;
    if (x % 2 == 0)
        cout << x << " is an even integer";
    else
        cout << x << " is an odd integer";
    return 0;
}