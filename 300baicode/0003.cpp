#include <iostream>
using namespace std;
int cv(int a, int b)
{
    return 2 * (a + b);
}
int dt(int a, int b)
{
    return a * b;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << cv(a, b) << ' ' << dt(a, b);
    return 0;
}