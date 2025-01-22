#include <iostream>
#include <iomanip>
using namespace std;
float TBC(int a, int b, int c)
{
    return float(a + b + c) / 3;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(1) << TBC(a, b, c);
    return 0;
}