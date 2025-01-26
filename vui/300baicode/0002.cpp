#include <iostream>
#include <iomanip>
using namespace std;
float cv(int r)
{
    return r * 2 * 3.14;
}
float dt(int r)
{
    return r * r * 3.14 ;
}
int main()
{
    int r;
    cin >> r;
    cout <<fixed << setprecision(2) << cv(r) << ' ' << dt(r);
    return 0;
}